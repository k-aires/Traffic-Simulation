//! Copyright [2018] <Helena Kunz Aires>
//! Copyright [2018] <Arthur Mesquita Pickcius>

#ifndef STRUCTURES_ARRAY_LIST_HPP
#define STRUCTURES_ARRAY_LIST_HPP

#include <cstdint>
#include <stdexcept>

namespace structures {

//! Classe Fila
/* Implementação de fila em vetor
 * Características:
 *  Pode ou não ser ordenada
 *  Dados entram apenas no final e saem apenas do início
 *  A retirada de um dado pode ser feita apenas por posição, sendo permitido tirar apenas o primeiro
 */
template<typename T>
class ArrayQueue {
 public:
     ArrayQueue();
     explicit ArrayQueue(std::size_t max_size);
     ~ArrayQueue();

     void enqueue(const T& data);

     void clear();
     T dequeue();
     T& back();

     bool full() const;
     bool empty() const;

     std::size_t size() const;
     std::size_t max_size() const;

 private:
     T* contents;  //! Vetor genérico que armazena a fila
     std::size_t size_;  //! Tamanho atual da fila, 0 se vazia
     std::size_t max_size_;  //! Tamanho máximo da fila
     std::size_t front_;  //! Posição do primeiro no vetor

     static const auto DEFAULT_MAX = 10u;  //! Tamanho padrão da fila
};

//! Construtor padrão
/* Inicia a fila com valores padrão
 * Não possui parâmetros
 * Utiliza o construtor com parâmetros
 */
template<typename T>
ArrayQueue<T>::ArrayQueue() : ArrayQueue(DEFAULT_MAX) {}

//! Construtor com parâmetros
/* Inicia a fila com os parâmetros passados
 * \param max (size_t) = indica o tamanho máximo da fila
 */
template<typename T>
ArrayQueue<T>::ArrayQueue(std::size_t max) : max_size_{max}, size_{0u}, contents{new T[max]}, front_{0u} {}

//! Destrutor
/* Utilizado ao fim do escopo de utilização da fila
 * Deleta a fila da memória
 */
template<typename T>
ArrayQueue<T>::~ArrayQueue() {
    if (contents) delete []contents;
}

//! Inserção no fim da fila
/* Insere o dado passado no final da fila, sempre
 * Exception ocorrerá em caso de fila cheia
 * /param data (const T&) = o dado a ser inserido
 */
template<typename T>
void ArrayQueue<T>::enqueue(const T& data) {
    if (size_ == max_size_) throw std::out_of_range("Fila cheia");

    auto position = (size_ + front_) % max_size_;
    size_++;
    contents[position] = data;
}

//! Limpa a fila
/* Atualiza o tamanho da fila para zero, sem retirar elementos
 */
template<typename T>
void ArrayQueue<T>::clear() {
    size_ = 0u;
    front_ = 0u;
}

//! Retirada no início da fila
/* Retira o dado inicial da fila e o retorna
 */
template<typename T>
T ArrayQueue<T>::dequeue() {
    if (size_ == 0u) throw std::out_of_range("Fila vazia");

    auto data = contents[front_];
    for (auto i = 0u; i < size_; i++) {
        auto position = (i + front_) % max_size_;
        contents[position] = contents[position+1%max_size_];
    }
    return data;
}

//! Retorna o fim da fila
/* Retorna o último dado da fila, sem retirá-lo
 */
template<typename T>
T& ArrayQueue<T>::back() {
    auto position = (size_-1 + front_) % max_size_;
    return contents[position];
}

//! Verificação de fila cheia
/* Verifica se a fila está ou não cheia
 */
template<typename T>
bool ArrayQueue<T>::full() const {
    return size_ == max_size_;
}

//! Verificação de fila vazia
/* Verifica se a fila está ou não vazia
 */
template<typename T>
bool ArrayQueue<T>::empty() const {
    return size_ == 0u;
}

//! Informa o tamanho atual
/* Retorna o tamanho atual da fila
 */
template<typename T>
std::size_t ArrayQueue<T>::size() const {
    return size_;
}

//! Informa o tamanho máximo
/* Retorna o tamanho máximo que a fila pode ter
 */
template<typename T>
std::size_t ArrayQueue<T>::max_size() const {
    return max_size_;
}

}  // namespace structures

#endif
