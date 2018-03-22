#define debug(args...)     (Debugger()) , args
#define DBG(x...) {cerr << #x << " = ";debug(x);}
#define _PR_(os,v) {bool f = 1;os << "[";for(auto i:v){if(!f)os << ", ";os << i;f = 0;}return os << "]";}

template <typename T1, typename T2>
inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){
    return os << "(" << p.first << ", " << p.second << ")";
}
template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    _PR_(os,v)
template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
    _PR_(os,v)
template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
    _PR_(os,v)

class Debugger{
    bool first;
    std::string separator;
    public:
    Debugger(const std::string& _separator = ", "):
    first(true), separator(_separator){}

    template<typename ObjectType>
    Debugger& operator , (const ObjectType& v){
        if(!first)
            std::cerr << separator;
        std::cerr << v;
        first = false;
        return *this;
    }
    ~Debugger() {  std::cerr << endl;}
};
