namespace lasd {
  // Specific constructor
  template <typename Data>
  List<Data>::Node::Node(Data newValue){
    value = newValue;
  }

  // Copy constructor
  template <typename Data>
  List<Data>::Node::Node(const Data& copyFrom){
    value = copyFrom.value;
  }

  // Move constructor
  template <typename Data>
  List<Data>::Node::Node(Data&& moveFrom){
    
  }
}
