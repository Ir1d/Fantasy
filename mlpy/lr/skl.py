# -*- coding: utf-8 -*-
import numpy as np
from sklearn import linear_model
from sklearn.preprocessing import StandardScaler

def linearRegression():
  print(u"loading...\n")
  data = loadtxtAndcsv_data("data.txt", ",", np.float64)
  X = np.array(data[:, 0: -1], dtype=np.float64) # X is col 0 to -2
  Y = np.array(data[:, -1], dtype=np.float64) # Y is col -1

  # normalize
  scaler = StandardScaler()
  scaler.fit(X)
  x_train = scaler.transform(X)
  X_test = scaler.transform(np.array([1650, 3]))
  
  # fit
  model = linear_model.LinearRegression()
  model.fit(x_train, y)

  # results
  result = model.predic(x_test)
  print(model.coef_) # coefficients
  print(model.intecept_) # bias
  print(result)

def loadtxtAndcsv_data(fileName, split, dataType):
  return np.loadtxt(fileName, delimiter=split, dtype=dataType)

def loadnpy_data(fileName):
  return np.load(fileName)

if __name__ == "__main__":
  linearRegression()