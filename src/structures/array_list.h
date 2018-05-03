//! Copyright [2018] <Helena Kunz Aires>

#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>
#include <stdexcept>

namespace structures {

//! Classe Lista
/* Implementação de lista em vetor
 * Características:
 *  Pode ou não ser ordenada
 *  Não há ordem necessária de entrada ou saída do dado
 *  A retirada de um dado pode ser feita por índice ou pelo próprio dado
 */
template<typename T>
class ArrayList {
 public:
     ArrayList();
     explicit ArrayList(std::size_t max_size);
     ~ArrayList();

     void push_back(const T& data);
     void push_front(const T& data);
     void insert(const T& data, std::size_t index);
     void insert_sorted(const T& data);

     void clear();
     T pop(std::size_t index);
     T pop_back();
     T pop_front();
     void remove(const T& data);

     bool full() const;
     bool empty() const;
     bool contains(const T& data) const;

     std::size_t find(const T& data) const;
     std::size_t size() const;
     std::size_t max_size() const;

     T& at(std::size_t index);
     const T& at(std::size_t index) const;
     T& operator[](std::size_t index);
     const T& operator[](std::size_t index) const;

 private:
     T* contents;  //! Vetor genérico que armazena a lista
     std::size_t size_;  //! Tamanho atual da lista, 0 se vazia
     std::size_t max_size_;  //! Tamanho máximo da lista

     static const auto DEFAULT_MAX = 10u;  //! Tamanho padrão da lista
};

//! Construtor padrão
/* Inicia a lista com valores padrão
 * Não possui parâmetros
 * Utiliza o construtor com parâmetros
 */
template<typename T>
ArrayList<T>::ArrayList() : ArrayList(DEFAULT_MAX) {}

//! Construtor com parâmetros
/* Inicia a lista com os parâmetros passados
 * \param max (size_t) = indica o tamanho máximo da lista
 */
template<typename T>
ArrayList<T>::ArrayList(std::size_t max) : max_size_{max}, size_{0u}, contents{new T[max]} {}

//! Destrutor
/* Utilizado ao fim do escopo de utilização da lista
 * Deleta a lista da memória
 */
template<typename T>
ArrayList<T>::~ArrayList() {
    if (contents) delete []contents;
}

//! Inserção no fim da lista
/* Insere o dado passado no final da lista, sempre
 * Exception ocorrerá em caso de lista cheia
 * /param data (const T&) = o dado a ser inserido
 */
template<typename T>
void ArrayList<T>::push_back(const T& data) {
    if (size == max_size_) throw std::out_of_range("Lista cheia");
    contents[size_] = data;
    size_++;
}

//! Inserção no início da lista
/* Insere o dado passado no início da lista, sempre
 * Exception ocorrerá em caso de lista cheia
 * /param data (const T&) = o dado a ser inserido
 */
template<typename T>
void ArrayList<T>::push_front(const T& data) {
    if (size == max_size_) throw std::out_of_range("Lista cheia");
    insert(data, 0u);
}

//! Inserção em posição específica
/* Insere o dado na posição passada por parâmetro
 * Exception ocorrerá em caso de lista cheia ou índice inválido
 * /param data (const T&) = o dado a ser inserido
 * /param index (size_t) = a posição na qual o dado deve ser inserido
 */
template<typename T>
void ArrayList<T>::insert(const T& data, std::size_t index) {
    if (size_ == max_size_) throw std::out_of_range("Lista cheia");
    else if (index > size_) throw std::out_of_range("Index inválido");
    else if (index == size_) push_back(data);

    for (auto i = size_; i > index; i++) {
        contents[i] = contents[i-1];
    }
    contents[index] = data;
    size_++;
}

//! Inserção ordenada
/* Insere o dado em ordem, partindo do princípio que a lista já está ordenada
 * Exception ocorrerá em caso de lista cheia
 * /param data (const T&) = o dado a ser inserido
 */
template<typename T>
void ArrayList<T>::insert_sorted(const T& data) {
    if (size_ == max_size_) throw std::out_of_range("Lista cheia");
    else if (data > contents[size_-1]) push_back(data);

    for (auto i = 0u; i < size_; i++) {
        if (data < contents[i]) {
            insert(data, i);
            break;
        }
    }
}

//! Limpa a lista
/* Atualiza o tamanho da lista para zero, sem retirar elementos
 */
template<typename T>
void ArrayList<T>::clear() {
    size_ = 0u;
}

//! Retirada em posição específica
/* Retira um dado da lista em uma posição especificada e o retorna
 * Exception ocorrerá em caso de lista vazia ou index inválido
 * /param index (size_t) = a posição da qual o dado deve ser retirado
 */
template<typename T>
T ArrayList<T>::pop(std::size_t index) {
    if (size_ == 0u) throw std::out_of_range("Lista vazia");
    else if (index >= size_) throw std::out_of_range("Index inválido");
    else if (index == size_-1) return pop_back();

    auto data = contents[index];
    for (auto i = index; i < size_-1; i++) {
        contents[i] = contents[i+1];
    }
    size_--;
    return data;
}

//! Retirada no fim da lista
/* Retira o dado final da lista e o retorna
 * Exception ocorrerá em caso de lista vazia
 */
template<typename T>
T ArrayList<T>::pop_back() {
    if (size_ == 0u) throw std::out_of_range("Lista vazia");

    size_--;
    return contents[size_];
}

//! Retirada no início da lista
/* Retira o dado inicial da lista e o retorna
 * Chama pop
 */
template<typename T>
T ArrayList<T>::pop_front() {
    return pop(0);
}

//! Remoção de dado específico
/* Retira um dado específico da lista
 * Chama pop e find
 * /param data (const T&) = o dado a ser retirado
 */
template<typename T>
void ArrayList<T>::remove(const T& data) {
    pop(find(data));
}

//! Verificação de lista cheia
/* Verifica se a lista está ou não cheia
 */
template<typename T>
bool ArrayList<T>::full() const {
    return size_ == max_size_;
}

//! Verificação de lista vazia
/* Verifica se a lista está ou não vazia
 */
template<typename T>
bool ArrayList<T>::empty() const {
    return size_ == 0u;
}

//! Verificação de dado
/* Verifica se o dado existe ou não na lista
 * /param data (const T&) = o dado a ser verificado
 */
template<typename T>
bool ArrayList<T>::contains(const T& data) const {
    return find(data) != size_;
}

//! Procura de item
/* Procura o dado passado e retorna sua posição
 * Retorna o tamanho da lista caso não seja encontrado
 * /param data (const T&) = o dado a ser procurado
 */
template<typename T>
std::size_t ArrayList<T>::find(const T& data) const {
    if (size_ == 0u) return size_;

    for (auto i = 0u; i < size_; i++)
        if (data == contents[i]) return i;

    return size_;
}

//! Informa o tamanho atual
/* Retorna o tamanho atual da lista
 */
template<typename T>
std::size_t ArrayList<T>::size() const {
    return size_;
}

//! Informa o tamanho máximo
/* Retorna o tamanho máximo que a lista pode ter
 */
template<typename T>
std::size_t ArrayList<T>::max_size() const {
    return max_size_;
}

//! Referencia o índice pedido
/* Retorna o dado no index pedido, sem retirá-lo
 * Possui verificação do index
 * Exception poderá ocorrer em caso de índice inválido
 * /param index (size_t) = o índice a ser acessado
 */
template<typename T>
T& ArrayList<T>::at(std::size_t index) {
    if (index >= size_) throw std::out_of_range("Index inválido");
    return contents[index];
}

//! Referencia o índice pedido
/* Retorna o dado no index pedido, sem retirá-lo
 * Garante que nada será alterado no método
 * Possui verificação do index
 * Exception poderá ocorrer em caso de índice inválido
 * /param index (size_t) = o índice a ser acessado
 */
template<typename T>
const T& ArrayList<T>::at(std::size_t index) const {
    if (index >= size_) throw std::out_of_range("Index inválido");
    return contents[index];
}

//! Referencia o índice pedido
/* Retorna o dado do index pedido, sem retirá-lo
 * /param index (size_t) = o índice a ser acessado
 */
template<typename T>
T& ArrayList<T>::operator[](std::size_t index) {
    return contents[index];
}

//! Referencia o índice pedido
/* Retorna o dado do index pedido, sem retirá-lo
 * Garante que nada será alterado no método
 * /param index (size_t) = o índice a ser acessado
 */

template<typename T>
const T& ArrayList<T>::operator[](std::size_t index) const {
    return contents[index];
}

}  // namespace structures

#endif
