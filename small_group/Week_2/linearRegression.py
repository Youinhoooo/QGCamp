import numpy as np


class linearRegression:
    # 最小二乘法
    def fit(self, X, y):
        X = np.asmatrix(X.copy())  # X转换为矩阵
        y = np.asmatrix(y).reshape(-1, 1)  # y转换为向量
        # 通过公式推导得出
        self.w = (X.T * X).I * X.T * y

    def predict(self, X):
        X = np.asmatrix(X.copy())
        result = X * self.w
        return np.asarray(result).ravel()  # 进行扁平化处理
        # 梯度下降法

    def cost_function(self, data, theta, y):
        cost = np.sum((data.dot(theta) - y) ** 2)
        #m = data.shape[1]
        return cost / (2 * m)

    def gradient(self, data, theta, y):
        grad = np.empty(len(theta))
        grad[0] = np.sum(data.dot(theta) - y)
        for i in range(1, len(theta)):
            grad[i] = (data.dot(theta) - y).dot(data[:, i])
        return grad

    def gradient_descent(self, data, theta, y, eta):
        while True:
            last_theta = theta
            #y = np.asarray(y)
            grad = linearRegression.gradient(self,data, theta, y)
            theta = theta - eta * grad
            print(theta)
            if abs(linearRegression.cost_function(self,data, last_theta, y) - linearRegression.cost_function(self,data, theta, y)) < 1e-15:
                break
        return theta
