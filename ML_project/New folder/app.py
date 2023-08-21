import streamlit as st
from joblib import load
import numpy as np

# Load the trained model
try:
    model = load("Real.joblib")
except Exception as e:
    st.error(f"Error loading the model: {e}")
    st.stop()

def predict_price(inputs):
    input_data = np.array(inputs).astype(np.float64)
    prediction = model.predict([input_data])
    return float(prediction[0])

def main():
    st.title("Real Estate Price Prediction")

    # st.markdown("""<div style="background-color:#025246 ;padding:10px">
    # <h2 style="color:white; text-align:center;">REAL ESTATE PREDICTION</h2>
    # </div>""")

    input_fields = [
        "per capita crime rate by town",
        "proportion of residential land zoned for lots over 25,000 sq.ft",
        "proportion of non-retail business acres per town",
        "Charles River dummy variable (= 1 if tract bound river; 0 otherwise)",
        "nitric oxides concentration (parts per 10 million)",
        "average number of rooms per dwelling",
        "proportion of owner-occupied units built prior to 1940",
        "weighted distances to five Boston employment centres",
        "index of accessibility to radial highways",
        "full-value property-tax rate per $10,000",
        "pupil-teacher ratio by town",
        "1000(Bk - 0.63)^2 where Bk is the proportion of blacks by town",
        "percentage lower status of the population",
    ]

    input_values = st.text_area("Enter feature values separated by commas", "0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0")

    if st.button("Predict"):
        inputs = list(map(float, input_values.split(',')))
        if len(inputs) == len(input_fields):
            output = predict_price(inputs)
            st.markdown(f"Predicted Price: {output:.2f}")
        else:
            st.warning("Please enter values for all features.")

if __name__ == '__main__':
    main()
