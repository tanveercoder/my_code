import pandas as pd
housing=pd.read_csv("C:\Users\Acer\Desktop\ML_project/housing.csv")
housing.head()
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
train_set,test_set=train_test_split(housing, test_size=.2,random_state=42)
from sklearn.model_selection import StratifiedShuffleSplit
split= StratifiedShuffleSplit(n_splits=1,test_size=0.2,random_state=42)
for train_index,test_index in split.split(housing,housing['CHAS']):
    strat_train_set=housing.loc[train_index]
    strat_test_set=housing.loc[test_index]
strat_test_set['CHAS'].value_counts()
strat_train_set['CHAS'].value_counts()
housing=strat_train_set.copy()

housing["TAXRM"]=housing['TAX']/housing['RM']
housing=strat_train_set.drop("MEDV",axis=1)
housing_labels=strat_train_set["MEDV"].copy()

#pipeline
from sklearn.impute import SimpleImputer
imputer=SimpleImputer(strategy="median")
imputer.fit(housing)
x=imputer.transform(housing)
housing_tr=pd.DataFrame(x,columns=housing.columns)
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import StandardScaler
mypipeline=Pipeline([('imputer',SimpleImputer(strategy="median")),
                     #......add as many as you want in your pipeline
                     ("std_scaler",StandardScaler()),
                     ])
housing_num_tr=mypipeline.fit_transform(housing_tr)

import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.tree import DecisionTreeRegressor
from sklearn.ensemble import  RandomForestRegressor

model=RandomForestRegressor()
model.fit(housing_num_tr,housing_labels)

model.fit(housing_num_tr,housing_labels)
some_data=housing.iloc[:5]
some_labels=housing_labels.iloc[:5]
prepared_data=mypipeline.transform(some_data)
model.predict(prepared_data)
list(some_labels)
some_data=housing.iloc[:5]

from sklearn.metrics import mean_squared_error
housing_predictions=model.predict(housing_num_tr)

from sklearn.model_selection import cross_val_score
scores=cross_val_score(model,housing_num_tr,housing_labels,scoring="neg_mean_squared_error",cv=10)
rmse_scores=np.sqrt(-scores)

from joblib import dump, load
dump(model,"Real.joblib")