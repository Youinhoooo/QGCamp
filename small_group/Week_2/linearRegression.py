import numpy as np


class linearRegression:
    # 最小二乘法
    def __init__(self,X,y):
        self.X = X
        self.y = y

    def fit(self):
        _X = np.asmatrix(self.X.copy())  # X转换为矩阵
        _y = np.asmatrix(self.y).reshape(-1, 1)
        # 通过公式推导得出
        self.w = (_X.T * _X).I * _X.T * _y

    def predict(self,X):
        X = np.asmatrix(X.copy())
        result = X * self.w
        return np.asarray(result).ravel()  # 进行扁平化处理

        # 梯度下降法
    def cost_function(self, theta):
        X = np.array(self.X)
        y = np.array(self.y)
        cost = np.sum((X.dot(theta) - y) ** 2)
        #cost = 1
        m = len(theta)
        return cost / (2 * m)

    def gradient(self, theta):
        X = np.array(self.X)
        y = np.array(self.y)
        grad = np.empty(len(theta))

        grad[0] = np.sum(X.dot(theta) - y)
        for i in range(1, len(theta)):
            temp = np.dot(X,theta)-y
            grad[i] = np.dot(temp,X[:,i])
        return grad

    def gradient_descent(self, theta, eta, times):
        for i in range(times):
            last_theta = theta
            grad = self.gradient(theta)
            theta = theta - eta * grad
            if abs(self.cost_function(last_theta) - self.cost_function(theta)) < 1e-15:
                break
        return theta