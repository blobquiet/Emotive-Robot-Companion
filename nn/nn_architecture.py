import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, InputLayer, Dropout, Conv1D, Conv2D, Flatten, Reshape, MaxPooling1D, MaxPooling2D, BatchNormalization, TimeDistributed
from tensorflow.keras.optimizers import Adam

# model architecture
model = Sequential()
# Data augmentation, which can be configured in visual mode
model.add(tf.keras.layers.GaussianNoise(stddev=0.45))
model.add(Reshape((int(input_length / 13), 13), input_shape=(input_length, )))
model.add(Conv1D(8, kernel_size=3, activation='relu', padding='same'))
model.add(MaxPooling1D(pool_size=2, strides=2, padding='same'))
model.add(Dropout(0.25))
model.add(Conv1D(16, kernel_size=3, activation='relu', padding='same'))
model.add(MaxPooling1D(pool_size=2, strides=2, padding='same'))
model.add(Dropout(0.25))
model.add(Flatten())
model.add(Dense(classes, activation='softmax', name='y_pred'))

# this controls the learning rate
opt = Adam(lr=0.005, beta_1=0.9, beta_2=0.999)
# Data augmentation for spectrograms, which can be configured in visual mode.
# To learn what these arguments mean, see the SpecAugment paper:
# https://arxiv.org/abs/1904.08779
sa = SpecAugment(spectrogram_shape=[int(input_length / 13), 13], mF_num_freq_masks=3, F_freq_mask_max_consecutive=4, mT_num_time_masks=3, T_time_mask_max_consecutive=2, enable_time_warp=True, W_time_warp_max_distance=6, mask_with_mean=False)
train_dataset = train_dataset.map(int(input_length / 13), tf.data.experimental.AUTOTUNE)