%module example
%{ 
    #define SWIG_FILE_WITH_INIT
    #include "example.h"
  %}

%include "std_vector.i"

namespace std {
    %template(IntVector) vector<int>;
}

using namespace std;
typedef std::vector Vector;

Sack (int n,int w,Vector vect);
%include "example.h"