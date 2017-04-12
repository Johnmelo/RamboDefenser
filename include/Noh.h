#ifndef NOH_H
#define NOH_H



template<typename T>
class Noh
{
    public:
        T elemento;
        Noh<T> *next;
        int idx;
        Noh();
        virtual ~Noh();
    protected:
    private:
};

#endif // NOH_H
