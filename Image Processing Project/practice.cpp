#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class numbers{

  protected:
    vector<int > elements;
  public:
    numbers();
    numbers(numbers const &number);
    virtual ~numbers(){
      cout<<"asd"<<endl;
    }
    vector<int >& getElements(){
      return elements;
    }
    friend ostream& operator<<(ostream& os, numbers& a);


};

ostream& operator<<(ostream& os, numbers& a){
  os<<a.getElements()[0];
  return os;
}

numbers::numbers(){

}

numbers::numbers(numbers const &number){

  for(int i=0;i<number.elements.size();i++){
    elements.push_back(number.elements[i]);
  }

}


class odd : public numbers{

  private:
    int var1;
  public:
    odd();
    odd(odd const &o);
    ~odd();
    vector<int >& getElements(int i){
      cout<<i;
      return elements;
    }
    int& getInt(){
      return var1;
    }
    friend odd operator +(const odd& a, const odd& b){
      odd c;
      c.elements.push_back(a.elements[0]+b.elements[0]);
      return c;
    }
};

odd::odd(){
}
odd::odd(odd const &o):numbers(o){
  var1 = o.var1;
}

odd::~odd(){
  cout<<"asdfg";
}

class even : public numbers{

  public:
    even();
    even(even const &e);
    ~even();
};

even::even(){

}
even::even(even const &e):numbers(e){
}
even::~even(){
  cout<<"even destructor"<<endl;
}


template <typename T>
class test{
public:
  test(vector<T> arr);
};
template <typename T>
test<T>::test(vector<T> arr){
  cout<<arr.size()<<endl;
}

int main(int argc, char* argv[]){

  odd n;
  n.numbers::getElements().push_back(1);
  int a[4] = {1,2,3,4};
  test<int > t(n.numbers::getElements());

  return 0;
}
