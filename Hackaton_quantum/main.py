import streamlit as st
import numpy as np
import pandas as pd
from qiskit.quantum_info import SparsePauliOp
from qiskit.primitives import SamplerPub
from qiskit_algorithms import QAOA
from qiskit_algorithms.optimizers import COBYLA

# Configurarea paginii Streamlit
st.set_page_config(page_title="Quantum Railway Optimizer", layout="wide", page_icon="🚆")

# ==========================================
# 1. LOGICA CUANTICĂ (Backend)
# ==========================================

def construieste_hamiltonian(profituri, costuri, buget, penalizare):
    n = len(profituri)
    lista_pauli = []
    matrice_q = np.zeros((n, n))

    # 1. Maximizarea profitului
    for i in range(n):
        matrice_q[i, i] = -profituri[i]

    # 2. Adăugarea penalizării pentru buget
    for i in range(n):
        matrice_q[i, i] += penalizare * (costuri[i]**2 - 2 * buget * costuri[i])
        for j in range(n):
            if i != j:
                matrice_q[i, j] += 2 * penalizare * costuri[i] * costuri[j]

    deplasare_constanta = 0.0
    coeficienti_liniari = np.zeros(n)
    coeficienti_patratici = np.zeros((n, n))

    # Transformarea din biți clasici în Pauli-Z
    for i in range(n):
        valoare_q = matrice_q[i, i]
        deplasare_constanta += 0.5 * valoare_q
        coeficienti_liniari[i] -= 0.5 * valoare_q

    for i in range(n):
        for j in range(i + 1, n):
            valoare_q_ij = matrice_q[i, j] + matrice_q[j, i] # simetrizare
            if valoare_q_ij != 0:
                deplasare_constanta += 0.25 * valoare_q_ij
                coeficienti_liniari[i] -= 0.25 * valoare_q_ij
                coeficienti_liniari[j] -= 0.25 * valoare_q_ij
                coeficienti_patratici[i, j] = 0.25 * valoare_q_ij

    lista_pauli.append(("I" * n, deplasare_constanta))

    for i in range(n):
        if coeficienti_liniari[i] != 0:
            operatori_pauli = ["I"] * n
            operatori_pauli[i] = "Z"
            lista_pauli.append(("".join(operatori_pauli)[::-1], coeficienti_liniari[i]))

    for i in range(n):
        for j in range(i + 1, n):
            if coeficienti_patratici[i, j] != 0:
                operatori_pauli = ["I"] * n
                operatori_pauli[i] = "Z"
                operatori_pauli[j] = "Z"
                lista_pauli.append(("".join(operatori_pauli)[::-1], coeficienti_patratici[i, j]))

    return SparsePauliOp.from_list(lista_pauli)

def rezolva_qaoa(hamiltonian):
    """Rulează algoritmul hibrid QAOA pentru a găsi starea fundamentală."""
    sampler = Sampler()
    optimizer = COBYLA(maxiter=100) # Poți crește numărul pentru acuratețe
    qaoa = QAOA(sampler=sampler, optimizer=optimizer, reps=2)
    rezultat = qaoa.compute_minimum_eigenvalue(hamiltonian)
    return rezultat

# ==========================================
# 2. INTERFAȚA STREAMLIT (Frontend)
# ==========================================

st.title("🚆 Quantum Railway Route Optimizer")
st.markdown("Această aplicație folosește **algoritmul cuantic QAOA** pentru a selecta rutele optime de cale ferată, maximizând profitul fără a depăși bugetul. Rulează într-un mediu hibrid (Clasic-Cuantic).")

# --- BARA LATERALĂ PENTRU INPUT-URI ---
st.sidebar.header("⚙️ Parametrii Problemei")

numar_sine = st.sidebar.slider("Număr de rute posibile", min_value=2, max_value=6, value=3)
limita_buget = st.sidebar.number_input("Buget Maxim Disponibil ($)", min_value=1, value=4)
factor_penalizare = st.sidebar.slider("Factor Penalizare (P)", min_value=1.0, max_value=50.0, value=10.0, step=1.0, help="Cât de drastic penalizăm depășirea bugetului.")

st.sidebar.subheader("💰 Date Financiare Rute")
profituri = []
costuri = []

# Generare dinamică a inputurilor pentru fiecare rută
for i in range(numar_sine):
    col1, col2 = st.sidebar.columns(2)
    with col1:
        p = st.number_input(f"Profit Șina {i+1}", min_value=1, value=5 - i if 5-i > 0 else 1, key=f"p_{i}")
        profituri.append(p)
    with col2:
        c = st.number_input(f"Cost Șina {i+1}", min_value=1, value=2 if i==0 else (3 if i==1 else 1), key=f"c_{i}")
        costuri.append(c)

# --- ZONA PRINCIPALĂ ---
st.write("### 📊 Prezentare Generală a Datelor")
df_date = pd.DataFrame({
    "Ruta": [f"Șina {i+1}" for i in range(numar_sine)],
    "Profit Estimat": profituri,
    "Cost Construcție": costuri
})
st.dataframe(df_date, use_container_width=True)

# --- BUTONUL DE EXECUȚIE ---
if st.button("🚀 Rulează Optimizarea Cuantică (QAOA)", type="primary"):
    
    with st.spinner("Construim Hamiltonianul și rulăm circuitul cuantic... ⏳"):
        # 1. Creare Hamiltonian
        hamiltonian = construieste_hamiltonian(profituri, costuri, limita_buget, factor_penalizare)
        
        # 2. Rulare QAOA
        rezultat = rezolva_qaoa(hamiltonian)
        
        # 3. Procesare Rezultate
        # Qiskit returnează stările ca string, ex: '101'
        stare_optima = rezultat.best_measurement['bitstring']
        probabilitate = rezultat.best_measurement['probability']
        
        # Inversăm string-ul deoarece Qiskit folosește convenția little-endian
        stare_optima_corectata = stare_optima[::-1] 
        
        rute_alese = [i + 1 for i, bit in enumerate(stare_optima_corectata) if bit == '1']
        
        # Calcul metrici finale
        profit_total = sum([profituri[i-1] for i in rute_alese])
        cost_total = sum([costuri[i-1] for i in rute_alese])
        buget_respectat = cost_total <= limita_buget

    st.success("✅ Optimizare cuantică finalizată cu succes!")
    
    # --- AFIȘARE REZULTATE DE BUSINESS ---
    st.write("### 🎯 Decizia Algoritmului")
    
    col1, col2, col3 = st.columns(3)
    col1.metric("Rute Selectate", ", ".join([f"Șina {r}" for r in rute_alese]) if rute_alese else "Niciuna")
    col2.metric("Profit Total Maxim", f"{profit_total} $")
    col3.metric(
        "Cost Total / Buget", 
        f"{cost_total} / {limita_buget} $", 
        delta="În Buget" if buget_respectat else "Buget Depășit", 
        delta_color="normal" if buget_respectat else "inverse"
    )

    # --- AFIȘARE GRAFICE (Pentru Juriul Tehnic) ---
    st.write("### 📈 Probabilitățile Stărilor Cuantice (Histogramă)")
    
    # Extragem distribuția de probabilitate din rezultat
    # Formatăm stările pentru a respecta ordinea (stânga-dreapta)
    stari = list(rezultat.eigenstate.keys())
    probabilitati = list(rezultat.eigenstate.values())
    
    # Mapare pentru a face barchart în Streamlit
    df_probs = pd.DataFrame({
        "Stare Cuantică (Șinealese)": [s[::-1] for s in stari], 
        "Probabilitate": probabilitati
    }).sort_values(by="Probabilitate", ascending=False).head(10) # Afișăm top 10 soluții
    
    st.bar_chart(df_probs.set_index("Stare Cuantică (Șinealese)"))
    
    # --- DETALII TEHNICE (Ascunse by default pentru a nu speria utilizatorul) ---
    with st.expander("🛠️ Vezi Detaliile Backend-ului (Hamiltonian)"):
        st.code(str(hamiltonian), language="text")
        st.markdown("**Valoarea proprie minimă găsită (Energie):** " + str(rezultat.eigenvalue.real))
        
      
