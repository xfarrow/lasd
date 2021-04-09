namespace lasd {
  // Specific constructor
  template <typename Data>
  List<Data>::Node::Node(Data newValue){
    value = newValue;
    next = nullptr;
  }

  // Copy constructor
  template <typename Data>
  List<Data>::Node::Node(const Node& copyFrom){
    value = copyFrom.value;
  }

  // Move constructor
  template <typename Data>
  List<Data>::Node::Node(Node&& moveFrom){
    std::move(value, moveFrom.value);
    std::move(next, moveFrom.next);
  }
  template <typename Data>
  List<Data>::Node::Node(Data&& moveFrom){
    std::move(value, moveFrom);
  }

  // Comparison operator
  template <typename Data>
  bool List<Data>::Node::operator==(const Node& node) const noexcept{
    if(node.value == value) return true;
    else return false;
  }

  template <typename Data>
  bool List<Data>::Node::operator!=(const Node& node) const noexcept{
    if(node.value != value) return true;
    else return false;
  }

  template <typename Data>
  List<Data>::List(const LinearContainer<Data>& con){
    for(ulong i=0 ; i<con.Size() ; ++i){
      InsertAtBack(con[i]);
    }
  }

  template <typename Data>
  List<Data>::List(const List<Data>& copyFrom){
    for(ulong i=0 ; i<copyFrom.Size() ; ++i){
      InsertAtBack(copyFrom[i]);
    }
  }

  template <typename Data>
  List<Data>::List(List<Data>&& moveFrom){
    std::swap(size, moveFrom.size);
    std::swap(head, moveFrom.head);
    std::swap(tail, moveFrom.tail);
  }

  // Destructor
  template <typename Data>
  List<Data>::~List(){
    Clear();
  }

  // Copy assignment
  template <typename Data>
  List<Data>& List<Data>::operator=(const List<Data>& copyFrom){
    if(*this != copyFrom){
      Clear();
      for(ulong i=0 ; i<copyFrom.Size() ; ++i){
        InsertAtBack(copyFrom[i]);
      }
    }
    return *this;
  }

  // Move assignment
  template <typename Data>
  List<Data>& List<Data>::operator=(List<Data>&& moveFrom) noexcept{
    if(*this != moveFrom){
      Clear();
      std::swap(size, moveFrom.size);
      std::swap(head, moveFrom.head);
      std::swap(tail, moveFrom.tail);
    }
    return *this;
  }

  // Comparison operators
  template <typename Data>
  bool List<Data>::operator==(const List<Data>& list) const noexcept{
    if(this->size != list.Size()) return false;
    for(ulong i=0 ; i<(this->size) ; ++i){
      if((*this)[i] != list[i]) return false;
    }
    return true;
  }

  template <typename Data>
  bool List<Data>::operator!=(const List<Data>& list) const noexcept{
    return !(*this == list);
  }

  // Specific member functions
  template <typename Data>
  void List<Data>::InsertAtFront(const Data& data){
    struct Node* tmp = new Node(data);
    tmp->next = head;
    head = tmp;
    size++;
    if(size==1){
      tail = head;
    }
  }

  template <typename Data>
  void List<Data>::InsertAtFront(Data&& data){
    struct Node* tmp = new Node(data);
    tmp->next = head;
    head = tmp;
    size++;
    if(size==1){
      tail = head;
    }
  }

  template <typename Data>
  void List<Data>::RemoveFromFront(){
    if(head==nullptr){
      throw std::length_error("List is empty!");
    }else{
      struct Node* tmp = head;
      head = head->next;
      delete tmp;
      size--;
    }
  }

  template <typename Data>
  Data List<Data>::FrontNRemove(){
    if(head==nullptr){
      throw std::length_error("List is empty!");
    }else{
      Data value = head->value;
      RemoveFromFront();
      return value;
    }
  }

  template <typename Data>
  void List<Data>::InsertAtBack(const Data& data){
    if(size==0){
      InsertAtFront(data);
    }else{
      struct Node* last = new Node(data);
      tail->next = last;
      tail = last;
      size++;
    }
  }

  template <typename Data>
  void List<Data>::InsertAtBack(Data&& data){
    if(size==0){
      InsertAtFront(data);
    }else{
      struct Node* last = new Node(data);
      tail->next = last;
      tail = last;
      size++;
    }
  }

  template <typename Data>
  void List<Data>::Clear(){
    while(head!=nullptr){
      RemoveFromFront();
    }
  }

  template <typename Data>
  Data& List<Data>::Front() const{
    if(size==0){
      throw std::length_error("List is empty!");
    }else{
      return head->value;
    }
  }

  template <typename Data>
  Data& List<Data>::Back() const{
    if(size==0){
      throw std::length_error("List is empty!");
    }else{
      return tail->value;
    }
  }

  template <typename Data>
  Data& List<Data>::operator[](const ulong index) const{
    if(index>=size || index<0){
      throw std::out_of_range("Out of range!");
    }else{
      struct Node* tmp = head;
      for(ulong i=0 ; i<index ; ++i){
        tmp = tmp->next;
      }
      return tmp->value;
    }
  }

  template <typename Data>
  void List<Data>::MapPreOrder(const MapFunctor fun, void* par){
    MapPreOrder(fun, par, head);
  }

  template <typename Data>
  void List<Data>::MapPreOrder(MapFunctor function, void* par, struct Node* node){
    if(node == nullptr)
      return;
    function(node->value, par);
    MapPreOrder(function, par, node->next);
  }

  template <typename Data>
  void List<Data>::MapPostOrder(MapFunctor function, void* par){
    MapPostOrder(function, par, head);
  }

  template <typename Data>
  void List<Data>::MapPostOrder(MapFunctor function, void* par, struct Node* node){
  if(node == nullptr)
    return;
  MapPostOrder(function, par, node->next);
  function(node->value, par);
  }

  template <typename Data>
  void List<Data>::FoldPreOrder(FoldFunctor function, const void* constPar, void* par) const{
    FoldPreOrder(function, constPar, par, head);
  }

  template <typename Data>
  void List<Data>::FoldPreOrder(FoldFunctor function, const void* constPar, void* par, struct Node* node) const{
  if(node == nullptr)
    return;
  function(node->value, constPar, par);
  FoldPreOrder(function, constPar, par, node->next);
  }

  template <typename Data>
  void List<Data>::FoldPostOrder(FoldFunctor function, const void* constPar, void* par) const{
  FoldPostOrder(function, constPar, par, head);
}

  template <typename Data>
  void List<Data>::FoldPostOrder(FoldFunctor function, const void* constPar, void* par, struct Node* node) const{
  if(node == nullptr)
    return;
  FoldPostOrder(function, constPar, par, node->next);
  function(node->value, constPar, par);
  }
}
