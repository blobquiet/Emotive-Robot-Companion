import numpy as np
from scipy import stats
import statistics
import matplotlib.pyplot as plt
plt.style.use('ggplot')

# Scores obtained for the interaction appreciation by the control group
# The penalties due to late reaction have already been applied.
test = np.array([[4.0, 4, 2, 5, 4],
                    [2,   4, 3, 4, 5],
                    [2,   2, 1, 5, 5],
                    [4,   4, 2, 5, 5],
                    [4,   4, 3, 4, 2]])

# Scores obtained for the interaction appreciation by the test group
# The penalties due to late reaction have already been applied.
control    = np.array([[1.0, 3, 2, 5, 1],
                    [4  , 3, 1, 5, 3],
                    [5  , 3, 5, 2, 4],
                    [3  , 4, 1, 3, 2],
                    [2  , 1, 4, 3, 5],
                    [5  , 4, 2, 3, 2]])

# get the mean score of each participant
control_mean = np.nanmean(control, axis = 1)
test_mean    = np.nanmean(test, axis = 1)
print(control_mean)
print(test_mean)
# display both results
fig, ax = plt.subplots()
ax.boxplot((control_mean, test_mean), vert=True, showmeans=False,meanline=True,
           labels=('Control group score','Test group score'),patch_artist=True,
           medianprops={'linewidth': 2, 'color': 'purple'},
           meanprops={'linewidth': 2, 'color': 'red'})
plt.show()

# compute the p-value with T-test
_,p_value=stats.ttest_ind(control_mean,test_mean)
alpha = 0.05

print("===========================================")
print(" Variance of control group:", round(statistics.variance(control_mean), 3))
print(" Variance of test group:   ", round(statistics.variance(test_mean), 3))
print(' P-value for two tailed test is %f'%p_value)  
if p_value<=alpha:
    print(' Null hypothesis can be rejected')
else :
    print(' Null hypothesis cannot be rejected')
print("===========================================")








