swig -c++ -python -o example_wrap.cpp example.swig
echo "Be careful: take the good path that leads you to your python libraries..."
g++ -fPIC -c example.cpp example_wrap.cpp -I/opt/local/Library/Frameworks/Python.framework/Versions/2.7/include/python2.7/ 
ld -bundle -flat_namespace -undefined suppress -o _example.so *.o
echo "You are ready! Now execute your own python script"
