'''
Implementation of Kalman Filter
'''

import numpy as np


class KalmanFilter(object):
    def __init__(self, dt=1, stateVariance=1, measurementVariance=10, method="Velocity"):
        super(KalmanFilter, self).__init__()
        self.method = method
        self.stateVariance = stateVariance
        self.measurementVariance = measurementVariance
        self.dt = dt
        self.initModel()

    def initModel(self):
        """
        Initialize the matrices needed for the Kalman Filter
        """
        # Control vector
        if self.method == "Acceleration":
            self.u = 1
        else:
            self.u = 0

        # State transition matrix
        self.A = np.matrix([[1, self.dt, 0, 0],
                            [0, 1, 0, 0],
                            [0, 0, 1, self.dt],
                            [0, 0, 0, 1]])

        # Control matrix
        self.B = np.matrix([[self.dt**2/2],
                            [self.dt],
                            [self.dt**2/2],
                            [self.dt]])

        # Matrix to model the sensors: we only read the position
        self.H = np.matrix([[1, 0, 0, 0],
                            [0, 0, 1, 0]])

        # Covariance matrix of the state state matrix
        self.P = np.matrix(self.stateVariance*np.identity(self.A.shape[0]))

        # Covariance matrix of the sensor noise
        self.R = np.matrix(self.measurementVariance *
                           np.identity(self.H.shape[0]))

        # Process noise matrix of the external noise
        self.Q = np.matrix([[self.dt**4/4, self.dt**3/2, 0, 0],
                            [self.dt**3/2, self.dt**2, 0, 0],
                            [0, 0, self.dt**4/4, self.dt**3/2],
                            [0, 0, self.dt**3/2, self.dt**2]])

        # Erro covariance matric and state vector
        self.errorCov = self.P
        self.state = np.matrix([[0], [0], [0], [0]])

    def predict(self):
        """
        Prediction of the next state based on the previous state
        """

        # Predicted state (x_hat)
        self.predictedState = self.A * self.state + self.B * self.u

        # Predicted covariance matrix
        self.predictedErrorCov = self.A * self.errorCov * self.A.T + self.Q

        # Return the position
        temp = np.asarray(self.predictedState)

        return temp[0], temp[2]

    def update(self, currentMeasurement):
        """
        Correct the prediction with the measurements
        """

        # Kalman Gain
        self.kalmanGain = self.predictedErrorCov * self.H.T * \
            np.linalg.pinv(self.H * self.predictedErrorCov * self.H.T + self.R)

        # Update the state
        self.state = self.predictedState + self.kalmanGain * \
            (currentMeasurement - (self.H * self.predictedState))
        
        # Update the covariance matrix
        self.errorCov = self.predictedErrorCov - self.kalmanGain * self.H * self.predictedErrorCov
        #(np.identity(self.P.shape[0])
        
    def __str__(self) -> str:
        return f"{self.state[0]}, {self.state[2]}"
