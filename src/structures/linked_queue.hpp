//! Copyright [2018] <Helena Kunz Aires>
//! Copyright [2018] <Picoxels>

#ifndef STRUCTURES_LINKED_LIST_HPP
#define STRUCTURES_LINKED_LIST_HPP

#include <cstdint>
#include <stdexcept>

namespace structures {

//! Classe Fila
/* Implementação de fila lincada
 * Características:
 *  Não tem tamanho fixo
 *  Pode ou não ser ordenada
 *  Dados entram apenas no final e saem apenas do início
 *  A retirada de um dado pode ser feita apenas por posição, sendo permitido tirar apenas o primeiro
 */
template<typename T>
class LinkedQueue {
 public:
     LinkedQueue();
     ~LinkedQueue();

     void enqueue(const T& data);

     void clear();
     T dequeue();
     T& back();

     bool empty() const;

     std::size_t size() const;

 private:

     class Node {
      public:
          explicit Node(const T& data) : data_{data}, next_{nullptr} {}

          Node(const T& data, Node* next) : data_{data}, next_{next} {}

          T& data() {return data_;}

          const T& data() const {return data_;}

          Node* next() {return next_;}

          const Node* next() const {return next_;}

          void next(Node* node) {next_ = node;}

      private:
          T data_;
          Node* next_;
     };

     Node* head_;  // Nodo que aponta para o inicio
     Node* tail_;  // Nodo que aponta para o fim
     std::size_t size_;  // Tamanho da fila
};

//! Construtor padrão
/* Inicia a fila com valores padrão
 * Não possui parâmetros
 */
template<typename T>
LinkedQueue<T>::LinkedQueue() : head_{nullptr}, tail_{nullptr}, size_{0u} {}

//! Destrutor
/* Utilizado ao fim do escopo de utilização da fila
 * Deleta a fila da memória
 */
template<typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

//! Inserção no fim da fila
/* Insere o dado passado no final da fila, sempre
 * Exception ocorrerá em caso de fila cheia
 * /param data (const T&) = o dado a ser inserido
 */
template<typename T>
void LinkedQueue<T>::enqueue(const T& data) {
    if (size_ == 0u) {
        head_ = new Node(data);
        tail_ = head_;
    } else {
        tail_->next(new Node(data));
        tail_ = tail_->next();
    }
    size_++;
}

//! Limpa a fila
/* Atualiza o tamanho da fila para zero, sem retirar elementos
 */
template<typename T>
void LinkedQueue<T>::clear() {
    while (size_ > 0) {
        dequeue();
    }
}

//! Retirada no início da fila
/* Retira o dado inicial da fila e o retorna
 */
template<typename T>
T LinkedQueue<T>::dequeue() {
    if (size_ == 0u) {
        throw std::out_of_range("Fila vazia");
    } else {
        auto data = head_->data();
        auto helper = head_;
        head_ = head_->next();
        delete helper;
        size--;
        return data;
    }
}

//! Retorna o fim da fila
/* Retorna o último dado da fila, sem retirá-lo
 */
template<typename T>
T& LinkedQueue<T>::back() {
    if (size_ == 0u) {
        throw std::out_of_range("Fila vazia");
    } else {
        return tail_->data();
    }
}

//! Verificação de fila vazia
/* Verifica se a fila está ou não vazia
 */
template<typename T>
bool LinkedQueue<T>::empty() const {
    return size_ == 0u;
}

//! Informa o tamanho atual
/* Retorna o tamanho atual da fila
 */
template<typename T>
std::size_t LinkedQueue<T>::size() const {
    return size_;
}

}  // namespace structures

#endif
