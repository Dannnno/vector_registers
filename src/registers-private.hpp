template <int width, typename T>
vector_register<width, T>::vector_register()
    : _register(setZero<width, T>()) { }

template <int width, typename T>
vector_register<width, T>::vector_register(registerType register_) 
    : _register(register_) { }

template <int width, typename T>
vector_register<width, T>::vector_register(const vector_register<width, T>& other)
    : _register(other._register) { }

template <int width, typename T>
vector_register<width, T>::vector_register(T* address)
    : _register(load(address)) { }

template <int width, typename T>
vector_register<width, T>::vector_register(T value)
    : _register(set1<width, T>(value)) { }

// template <int width, typename T>
// registers::vector_register<width, T>& 
// registers::vector_register<width, T>::operator+=(const registerType register_) {
//     _register += register_;
//     return *this;
// }

// template <int width, typename T>
// registers::vector_register<width, T>& 
// registers::vector_register<width, T>::operator+=(const registers::vector_register<width, T> rhs) {
//     _register += rhs._register;
//     return *this;
// }

// template <int width, typename T>
// registers::vector_register<width, T>& 
// registers::vector_register<width, T>::operator+=(const T* address) {
//     registerType temp = load(address);
//     _register += temp;
//     return *this;
// }

// template <int width, typename T>
// registers::vector_register<width, T>& 
// registers::vector_register<width, T>::operator+=(const T value) {
//     registerType temp = setOne<width, T>(value);
//     _register += temp;
//     return *this;
// }

// template <>
// registers::vector_register<256, double> registers::load_a(double* address) {
//     return registers::vector_register<256, double>(_mm256_load_pd(address));
// }
// template <>
// registers::vector_register<256, float> registers::load_a(float* address) {
//     return registers::vector_register<256, float>(_mm256_load_ps(address));
// }
// template <>
// registers::vector_register<128, double> registers::load_a(double* address) {
//     return registers::vector_register<128, double>(_mm_load_pd(address));
// }
// template <>
// registers::vector_register<128, float> registers::load_a(float* address) {
//     return registers::vector_register<128, float>(_mm_load_ps(address));
// }

// template <>
// registers::vector_register<256, double> registers::load(double* address) {
//     return registers::vector_register<256, double>(_mm256_loadu_pd(address));
// }
// template <>
// registers::vector_register<256, float> registers::load(float* address) {
//     return registers::vector_register<256, float>(_mm256_loadu_ps(address));
// }
// template <>
// registers::vector_register<128, double> registers::load(double* address) {
//     return registers::vector_register<128, double>(_mm_loadu_pd(address));
// }
// template <>
// registers::vector_register<128, float> registers::load(float* address) {
//     return registers::vector_register<128, float>(_mm_loadu_ps(address));
// }


template <>
vector_register<256, double> setZero() {
    return vector_register<256, double>(_mm256_setzero_pd());
}
// template <>
// registers::vector_register<256, float> registers::setZero() {
//     return vector_register<256, float>(_mm256_setzero_ps());
// }
// template <>
// registers::vector_register<128, double> registers::setZero() {
//     return vector_register<128, double>(_mm_setzero_pd());
// }
// template <>
// registers::vector_register<128, float> registers::setZero() {
//     return registers::vector_register<128, float>(_mm_setzero_ps());
// }

// template <>
// registers::vector_register<256, double> registers::set1(double value) {
//     return registers::vector_register<256, double>(_mm256_set1_pd(value));
// }
// template <>
// registers::vector_register<256, float> registers::set1(float value) {
//     return registers::vector_register<256, float>(_mm256_set1_ps(value));
// }
// template <>
// registers::vector_register<128, double> registers::set1(double value) {
//     return registers::vector_register<128, double>(_mm_set1_pd(value));
// }
// template <>
// registers::vector_register<128, float> registers::set1(float value) {
//     return registers::vector_register<128, float>(_mm_set1_ps(value));
// }
