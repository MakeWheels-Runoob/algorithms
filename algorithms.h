/**
 * @file algorithms.h
 * @author Richard
 * @brief 
 * @version 0.4
 * @date 2020-11-25
 * This header file contains many useful functions.
 * @copyright Copyright (c) 2020
 */
#ifndef ALGORITHMS_H_
#define ALGORITHMS_H_ 1
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include "stdarg.h"
#ifdef DEBUG
#define LOG fprintf(stderr, "At function %s,line %d.\n", __FUNCTION__, __LINE__)
#endif
#define TEMPLATE(name) template <class name>
#define TEMPLATES(name1, name2) template <class name1, class name2>
#define TTEMPLATE(types, name) template <types name>
#define TTEMPLATES(type1, name1, type2, name2) template <type1 name1, type2 name2>

#define FOR(i, s, e) for (ull(i) = (s); (i) < (e); ++(i))
#define FORS(i, s, e, step) for (auto(i) = (s); (i) < (e); (i) += (step))
#define FORI(i, s, e) for (ull(i) = (s)-1; (i) >= (e); --(i))
#define FORIS(i, s, e, step) for (auto(i) = (s)-1; (i) >= (e); (i) -= (step))
#define FORE(i, a) for (auto && (i) : (a))

#define ll long long
#define ull unsigned long long

TEMPLATE(dT)
inline ull length(dT *array)
{
    return sizeof(array) / sizeof(dT);
}

TEMPLATE(dT)
dT sum(dT *data)
{
    dT sum = new dT();
    FOR(i, 0, length<dT><dT>(data))
    sum = sum + data[i];
    return sum;
}

#ifdef DEBUG
namespace error
{
    const enum ERROR {
        STACK = 50,
        QUEUE,
        LIST = 70,
        TREE = 80,
        GRAPH = 90,
        VECTOR = 100,
        MATRIX
    };
    class StructError
    {
    public:
        std::string msg, s;
        StructError(std::string msg, ERROR type)
        {
            switch (type)
            {
            case ERROR::STACK:
                s = "Stack";
                break;
            case ERROR::QUEUE:
                s = "Queue";
                break;
            case ERROR::LIST:
                s = "List";
                break;
            case ERROR::TREE:
                s = "Tree";
                break;
            case ERROR::GRAPH:
                s = "Graph";
                break;
            case ERROR::VECTOR:
                s = "Vector";
                break;
            case ERROR::MATRIX:
                s = "Matrix";
                break;
            }
            this->msg = s + "Error:" + msg;
        }
    };
} /* namespace error */
#endif

namespace Struct
{

    TEMPLATE(dT)
    class node
    {
        dT data;
        node<dT> *next, *pre;

    public:
        node()
        {
            next = nullptr;
            pre = nullptr;
        }
        node(nT data)
        {
            this->data = data;
            next = nullptr;
            pre = nullptr;
        }
    };

    TEMPLATE(dT)
    class stack
    {
        node<dT> *head;
        ull len;

    public:
        stack()
        {
            len = 0;
        }
        stack(dT data)
        {
            len = 0;
            head->data = data;
        }
        stack(dT *array)
        {
            head->data = array[0];
            node<dT> *pre = head;
            for (ull index = 1, len = 0; index < length<dT><dT>(array); index++, len++)
            {
                node<dT> *next = new node<dT>(array[index]);
                next->next = pre;
                pre->pre = next;
                pre = next;
            }
            head = pre;
        }
        ~stack()
        {
            node<dT> *now = head;
            do
            {
                now = now->next;
                delete now->pre;
            } while (now->next != nullptr);
            delete now;
            delete len;
        }
        stack operator=(const stack<dT> &s)
        {
            len = s.len;
            head->data = s.head->data;
            node<dT> *now = head, nows = s.head;
            while (nows->next)
            {
                now = now->next;
                nows = nows->next;
                if (now)
                {
                    now->data = nows->data;
                    continue;
                }
                now = node<dT>(nows->data);
            }
        }
        stack operator=(const dT *array)
        {
            len = length<dT>(array);
            node<dT> *now = head;
            FORE(i, array)
            {
                if (now)
                {
                    now->data = array[i];
                    now = now->next;
                }
                else
                {
                    now = new node(array[i]);
                    now = now->next;
                }
            }
        }
        void push(dT data)
        {
            node<dT> *n = new node<dT>(data);
            n->next = head;
            head->pre = n;
            ++len;
        }
        void pop()
        {
            node<dT> *n = head;
            head = head->next;
            delete n;
            --len;
        }
        dT top()
        {
            return head->data;
        }
        dT tpop()
        {
            dT data = this->top();
            this->pop();
            --len;
            return data;
        }
        dT ptop()
        {
            this->pop();
            --len;
            return this->top();
        }
        ull length<dT>()
        {
            return len;
        }
    }; /* class stack */

    TEMPLATE(dT)
    class queue
    {
        node<dT> *head, *tail;
        ull len;

    public:
        queue()
        {
            tail->next = head;
            head->pre = tail;
            len = 0;
        }
        queue(dT data)
        {
            tail->data = data;
            tail = tail->pre;
            len = 0;
        }
        queue(dT *array)
        {
            len = length<dT>(array);
            node<dT> *now = tail, *pre = head;
            FORE(i, array)
            {
                now->data = array[i];
                pre->pre = now;
                now->next = pre;
                pre = now;
                now = now->pre;
            }
            tail = now;
        }
        ~queue()
        {
            node<dT> *now = tail;
            while (now != nullptr)
            {
                now = now->next;
                delete now->pre;
            }
            delete now;
            delete len;
        }

        const queue &operator=(const queue &q);
        const queue &operator=(const dT *array);
    }; /* class queue */

    TEMPLATE(dT)
    class ud_list;

    TEMPLATE(dT)
    class ud_loop_list : public ud_list
    {
    public:
    };

    TEMPLATE(dT)
    class binary_tree
    {
        class node
        {
            dT data;
            node *left, *right;

        public:
            node() : data(0), left(nullptr), right(nullptr) {}
            node(dT data) : data(data), left(nullptr), right(nullptr) {}
        } * head;
        static void delete_node(node *now)
        {
            if (now->left)
                delete_node(now->left);
            if (now->right)
                delete_node(now->right);
            delete now;
        }
        static void build_tree(node *now, node *bt)
        {
            now->data = bt->data;
            if (bt->left)
            {
                if (now->left)
                    build_tree(now->left, bt->left);
                else
                {
                    now->left = new node();
                    build_tree(now->left, bt->left);
                }
            }
            if (bt->right)
            {
                if (now->right)
                    build_tree(now->right, bt->right);
                else
                {
                    now->right = new node();
                    build_tree(now->right, bt->right);
                }
            }
        }

    public:
        binary_tree() {}
        binary_tree(dT data)
        {
            head->data = data;
        }
        binary_tree(std::string types, dT *data)
        {
            if (types.length<dT>() != length<dT>(data))
            {
                return;
            }
            node *now = head;
            FOR(i, 0, types.length<dT>())
            {
                switch (types[i])
                {
                case 'L':
                case 'l':
                    if (now->left)
                    {
                        now = now->left;
                        now->data = data[i];
                    }
                    else
                    {
                        now->left = new node(data[i]);
                        now = now->left;
                    }
                    break;
                case 'R':
                case 'r':
                    if (now->right)
                    {
                        now = now->right;
                        now->data = data[i];
                    }
                    else
                    {
                        now->right = new node(data[i]);
                        now = now->right;
                    }
                    break;
                default:
                    return;
                }
            }
        }
        ~binary_tree()
        {
            delete_node(head);
        }
        binary_tree &insert(std::string types, dT data)
        {
            node *now = head;
            FOR(i, 0, types.length<dT>())
            {
                switch (types[i])
                {
                case 'L':
                case 'l':
                    if (now->left || i == types.length<dT>() - 1)
                    {
                        now = now->left;
                    }
                    else
                    {
                        return *this;
                    }
                    break;
                case 'R':
                case 'r':
                    if (now->right || i == types.length<dT>() - 1)
                    {
                        now = now->right;
                    }
                    else
                    {
                        return *this;
                    }
                    break;
                default:
                    return *this;
                }
            }
            if (now)
            {
                now->data = data;
            }
            else
            {
                now = new node(data);
            }
            return *this;
        }
        binary_tree &insert(std::string types, binary_tree<dT> bt)
        {
            node *now = head;
            FOR(i, 0, types.length<dT>())
            {
                switch (types[i])
                {
                case 'L':
                case 'l':
                    if (now->left || i == types.length<dT>() - 1)
                    {
                        now = now->left;
                    }
                    else
                    {
                        return *this;
                    }
                    break;
                case 'R':
                case 'r':
                    if (now->right || i == types.length<dT>() - 1)
                    {
                        now = now->right;
                    }
                    else
                    {
                        return *this;
                    }
                    break;
                default:
                    return *this;
                }
            }
            build_tree(now, bt->head);
            return *this;
        }
        dT query(std::string types)
        {
            node *now = head;
            FOR(i, 0, types.length<dT>())
            {
                switch (types[i])
                {
                case 'L':
                case 'l':
                    if (now->left)
                        now = now->left;
                    else
                        return nullptr;
                case 'R':
                case 'r':
                    if (now->right)
                        now = now->right;
                    else
                        return nullptr;
                default:
                    return nullptr;
                }
            }
            return now->data;
        }
    }; /* class binary_tree */

    TTEMPLATES(class, dT, int, dim)
    class tree : public binary_tree
    {
    public:
    };

    TEMPLATE(dT)
    class edge;

    TEMPLATE(dT)
    class point;

    TEMPLATES(eT, pT)
    class graph;
} /* namespace Struct */

namespace math
{
    TEMPLATE(eT)
    class reduce
    {
        /****************
         * > a=reduce<int>([](int a,int b){return a+b;});
         * > list={1,2,3};
         * > a(list); // 6
        ****************/
        eT (*func)(eT, eT);

    public:
        reduce(eT (*func)(eT, eT))
        {
            this->func = func;
        }
        eT operator()(eT *e)
        {
            eT ans = new eT();
            FORE(i, array)
            {
                ans = (*func)(ans, e[i]);
            }
            return ans;
        }
    }; /* class reduce */

    class complex
    {
    public:
        double real, imaginary;
        complex() {}
        complex(double real = 0.0, double imaginary = 0.0)
        {
            this->real = real;
            this->imaginary = imaginary;
        }
        ~complex() {}

        const complex &operator=(const complex &c)
        {
            real = c.real;
            imaginary = c.imaginary;
            return *this;
        }

        const double mod() const
        {
            return sqrt(real * real + imaginary * imaginary);
        }
        const complex &conjugate() const
        {
            return complex(real, -imaginary);
        }

        const complex &operator+(const complex &c) const
        {
            return complex(real + c.real, imaginary + c.imaginary);
        }
        const complex &operator-(const complex &c) const
        {
            return complex(real - c.real, imaginary - c.imaginary);
        }
        const complex &operator*(const complex &c) const
        {
            return complex(real * c.real - imaginary * c.imaginary, real * c.imaginary + imaginary * c.real);
        }
        const complex &operator/(const complex &c) const
        {
            return complex((real * c.real + imaginary * c.imaginary) / (c.real * c.real + c.imaginary * c.imaginary),
                           (imaginary * c.real - real * c.imaginary) / (c.real * c.real + c.imaginary * c.imaginary));
        }

        const complex &operator+=(const complex &c)
        {
            (*this) = (*this) + c;
            return *this;
        }
        const complex &operator-=(const complex &c)
        {
            (*this) = (*this) - c;
            return *this;
        }
        const complex &operator*=(const complex &c)
        {
            (*this) = (*this) * c;
            return *this;
        }
        const complex &operator/=(const complex &c)
        {
            (*this) = (*this) / c;
            return *this;
        }

        bool operator==(const complex &c) const
        {
            return real == c.real && imaginary == c.imaginary;
        }
        bool operator!=(const complex &c) const
        {
            return !((*this) == c);
        }
    }; /* class complex */

    TEMPLATE(dT)
    class vector;

    TEMPLATE(dT)
    class matrix;

    namespace model
    {
#define VMODEL(name) class name##VirusModel
        VMODEL()
        {
            ull susceptible;
            ull exposed;
            ull infectious;
            ull removed;
            double StoE;
            double StoI;
            double EtoI;
            double EtoR;
            double ItoR;
            double RtoS;

        public:
            VirusModel();
            void next(int step = 1);
            void print(FILE *file = stdout);
        }; /* class VirusModel */
        
        VMODEL(SI) : public VirusModel
        {
            ull susceptible;
            ull infectious;
            double StoI;

        public:
            SIVirusModel() {}
            SIVirusModel(ull s = 100, ull i = 1, double stoi = 0.5)
            {
                susceptible = s;
                infectious = i;
                StoI = stoi;
            }
            void next(int step = 1)
            {
                while (step--)
                {
                    susceptible += -StoI * susceptible * infectious;
                    infectious += StoI * susceptible * infectious;
                }
            }
            void print(FILE *file = stdout)
            {
                fprintf(file, "Susceptible:%d,Infector:%d\n", susceptible, infectious);
                fprintf(file, "ratio of from susceptible to infector:%f\n", StoI);
            }
        };
        VMODEL(SIS)
        {
            ull susceptible;
            ull infectious;
            double StoI;
            double ItoS;

        public:
            SISVirusModel() {}
            SISVirusModel(ull s = 100, ull i = 1, double stoi = 0.5, double itos = 0.5)
            {
                susceptible = s;
                infectious = i;
                StoI = stoi;
                ItoS = itos;
            }
            void next(int step = 1)
            {
                while (step--)
                {
                    susceptible += -StoI * susceptible * infectious + ItoS * susceptible * infectious;
                    infectious += StoI * susceptible * infectious - ItoS * susceptible * infectious;
                }
            }
            void print(FILE *file = stdout)
            {
                fprintf(file, "Susceptible:%d,Infectious:%d\n", susceptible, infectious);
                fprintf(file, "ratio of from susceptible to infectious:%f\n", StoI);
                fprintf(file, "ratio of from infectious to susceptible:%f\n", ItoS);
            }
        };
        VMODEL(SIR)
        {
            ull susceptible;
            ull infectious;
            ull removed;
            double StoI;
            double ItoR;

        public:
            SIRVirusModel() {}
            SIRVirusModel(ull s = 100, ull i = 1, ull r = 0, double stoi = 0.5, double itor = 0.5)
            {
                susceptible = s;
                infectious = i;
                removed = r;
                StoI = stoi;
                ItoR = itor;
            }
            void next(int step = 1)
            {
                while (step--)
                {
                    susceptible += -StoI * susceptible * infectious;
                    infectious += StoI * susceptible * infectious - ItoR * susceptible * infectious;
                }
            }
            void print(FILE *file = stdout)
            {
                fprintf(file, "Susceptible:%d,Infectious:%d,Removed:%d\n", susceptible, infectious, removed);
                fprintf(file, "ratio of from susceptible to infectious:%f\n", StoI);
                fprintf(file, "ratio of from infectious to removed:%f\n", ItoR);
            }
        };
    } /* namespace model */
} /* namespace math */

namespace type
{
    class BigInteger
    {
        bool sign; /* true -> +  false -> - */
        ull digit;
        std::vector<ull> data;
        static const ull MOD = 1000000000000000ULL;
        static const int WIDTH = 15;
        static ull str_to_ull(std::string str)
        {
            ull ans = 0;
            FORE(c, str)
            ans = ans * 10 + c - '0';
            return ans;
        }

    public:
        BigInteger() { digit = 0; }
        BigInteger(ll num)
        {
            sign = (num >= 0);
            while (num)
            {
                data.push_back(num % MOD);
                num /= MOD;
            }
            digit = data.size();
        }
        BigInteger(std::string str)
        {
            sign = (str[0] != '-');
            FORE(c, str)
            if (c < '0' || c > '9')
                goto end;
            FORIS(i, str.length(), WIDTH, WIDTH)
            data.push_back(str_to_ull(str.substr(i - WIDTH, WIDTH)));
            if (str.length() % WIDTH)
                data.push_back(str_to_ull(str.substr(0, str.length() % WIDTH)));
        end:
            digit = data.size();
        }
        bool is_zero() const
        {
            return !digit && data.empty() || !(digit - 1) && !data[0];
        }
        const BigInteger &operator=(const BigInteger &b)
        {
            sign = b.sign;
            digit = b.digit;
            data.clear();
            FORE(d, b.data)
            data.push_back(d);
            return *this;
        }
        const BigInteger &operator=(ll num)
        {
            sign = (num >= 0);
            data.clear();
            while (num)
            {
                data.push_back(num % MOD);
                num /= MOD;
            }
            digit = data.size();
            return *this;
        }
        const BigInteger &operator=(std::string str)
        {
            sign = (str[0] != '-');
            data.clear();
            FORE(c, str)
            if (c < '0' || c > '9')
                goto end;
            FORIS(i, str.length(), WIDTH, WIDTH)
            data.push_back(str_to_ull(str.substr(i - WIDTH, WIDTH)));
            if (str.length() % WIDTH)
                data.push_back(str_to_ull(str.substr(0, str.length() % WIDTH)));
        end:
            digit = data.size();
            return *this;
        }

        bool operator==(const BigInteger &b) const
        {
            return data == b.data;
        }
        bool operator<(const BigInteger &b) const
        {
            if (digit != b.digit)
                return digit < b.digit;
            FORI(i, digit, 0)
            {
                if (data[i] < b.data[i])
                    return true;
                if (data[i] > b.data[i])
                    return false;
            }
            return false;
        }
        bool operator>(const BigInteger &b) const
        {
            return b < *this;
        }
        bool operator!=(const BigInteger &b) const
        {
            return !(*this == b);
        }
        bool operator<=(const BigInteger &b) const
        {
            return *this < b || *this == b;
        }
        bool operator>=(const BigInteger &b) const
        {
            return *this > b || *this == b;
        }

        TEMPLATE(dT)
        bool operator==(const dT &data) const
        {
            BigInteger b = data;
            return *this == b;
        }
        TEMPLATE(dT)
        bool operator!=(const dT &data) const
        {
            BigInteger b = data;
            return *this != b;
        }
        TEMPLATE(dT)
        bool operator<(const dT &data) const
        {
            BigInteger b = data;
            return *this < b;
        }
        TEMPLATE(dT)
        bool operator<=(const dT &data) const
        {
            BigInteger b = data;
            return *this <= b;
        }
        TEMPLATE(dT)
        bool operator>(const dT &data) const
        {
            BigInteger b = data;
            return *this > b;
        }
        TEMPLATE(dT)
        bool operator>=(const dT &data) const
        {
            BigInteger b = data;
            return *this >= b;
        }

        BigInteger &operator++()
        {
            if (sign)
            {
                ull now = 0;
                while (now < digit && data[now] + 1 >= MOD)
                {
                    data[now++] = 0;
                }
                if (now >= digit)
                {
                    data.push_back(1);
                    ++digit;
                }
                else
                {
                    data[now]++;
                }
            }
            else
            {
                ull now = 0;
                do
                {
                    --data[now];
                    if (data[now] >= 0)
                        break;
                    data[now] += MOD;
                    if (now + 1 == digit)
                    {
                        ++digit;
                        data.push_back(1);
                        break;
                    }
                } while (data[now] >= 0);
            }
            return *this;
        }
        BigInteger &operator++(int)
        {
            BigInteger b = *this;
            ++*this;
            return b;
        }
        BigInteger &operator-() const
        {
            BigInteger b = *this;
            b.sign = !b.sign;
            return b;
        }

        const BigInteger &operator+(const BigInteger &b) const
        {
            BigInteger ans;
            if (is_zero())
                return b;
            else if (b.is_zero())
                return *this;
            if (*this == b)
                return 0;
            ull g = 0;
            if (sign)
            {
                if (b.sign)
                {
                    ans.sign = true;
                    FOR(i, 0, std::max(digit, b.digit))
                    {
                        if (i >= digit)
                        {
                            ans.data.push_back((b.data[i] + g) % MOD);
                            g = (b.data[i] + g) / MOD;
                        }
                        else if (i >= b.digit)
                        {
                            ans.data.push_back((data[i] + g) % MOD);
                            g = (data[i] + g) / MOD;
                        }
                        else
                        {
                            ans.data.push_back((data[i] + b.data[i] + g) % MOD);
                            g = (data[i] + b.data[i] + g) / MOD;
                        }
                    }
                }
                else
                {
                    ans.sign = *this > b;
                    // TODO: postive add negtive
                }
            }
            else
            {
                if (b.sign)
                {
                    ans.sign = *this < b;
                    // TODO: negtive add postive
                }
                else
                {
                    ans.sign = false;
                    // TODO: negtive add negtive
                }
            }
            return ans;
        }
        const BigInteger &operator-(const BigInteger &b) const;
    }; /* class BigInteger */
    
    class BigDecimal
    {
        bool sign;
        ull digit;
        ull decimalDigit;
        std::vector<ull> data;
        std::vector<ull> d_data;
        static const ull kMOD = 1000000000000000ULL;
        static const int kWIDTH = 15;
        static const long double kMOD_OF_DECIMAL = 0.;
    }; /* class BigDecimal */
} /* namespace type */
#endif /*ALGORITHMS_H_*/
