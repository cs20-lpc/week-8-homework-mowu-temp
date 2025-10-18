template <typename T>
LinkedListStack<T>::LinkedListStack() {
    top = nullptr;
}

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    while(top != nullptr) {
        Node<T> * old = top;
        top = top->next;
        delete old;
    }
    this->length = 0;
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    clear();
    this->length = copyObj.length;
    if (this->length > 0) {
        top = new Node<T>(copyObj.top->value);
        Node<T> * currA = top;
        Node<T> * currB = copyObj.top;
        while(currB->next != nullptr) {
            currA->next = new Node<T>(currB->next->value);
            currB = currB->next;
            currA = currA->next;
        }
    }

    
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    if (this->length == 0) {
        throw string("peek: error, no elements");
    } 
    return top->data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    if (this->length == 0) {
        throw string("pop: error, no elements");
    }
    Node<T> * old = top;
    top = top->next;
    delete old;
    this->length--;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    Node<T> * newNode = new Node<T>(elem);
    newNode->next = top;
    top = newNode;
    this->length++;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    if (this->length <= 1) {
        return;
    }
    if (dir == Stack<T>::LEFT) {
        Node<T> * prev = top;
        Node<T> * last = top->next;
        while(last->next != nullptr) {
            prev = last;
            last = last->next;
        }
        prev->next = nullptr;
        last->next = top;
        top = last;
        
    } else if (dir == Stack<T>::RIGHT) {
        Node<T> * last = top;
        while(last->next != nullptr) {
            last = last->next;
        }
        Node<T> * newTop = top->next;
        last->next = top;
        top->next = nullptr;
        top = newTop;

    } else {
        throw string("rotate: unknown direction");
    }
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}
