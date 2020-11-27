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
#define ALGORITHMS_H_
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>

#ifdef DEBUG
#define LOG fprintf(stderr, "At function %s,line %d.\n", __FUNCTION__, __LINE__)
#else
#define LOG
#endif
#define TEMPLATE(name) template <class name>
#define TEMPLATE_TWO_NAME(name1, name2) template <class name1, class name2>
#define SET_TYPE_TEMPLATE(type, name) template <type name>
#define SET_TYPE_TEMPLATE_TWO_NAME(type1, name1, type2, name2) template <type1 name1, type2 name2>

#define FOR(i, s, e) for (ull(i) = (s); (i) < (e); ++(i))
#define FOR_SET_STEP(i, s, e, step) for (auto(i) = (s); (i) < (e); (i) += (step))
#define FOR_REVERSE(i, s, e) for (ull(i) = (s)-1; (i) >= (e); --(i))
#define FOR_REVERSE_SET_STEP(i, s, e, step) for (auto(i) = (s)-1; (i) >= (e); (i) -= (step))
#define FOR_RANGE(i, a) for (auto && (i) : (a))

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
    FOR(i, 0, length<dT>(data))
    sum = sum + data[i];
    return sum;
}

#ifdef DEBUG
#ifndef ERROR_NAMESPACE_
#define ERROR_NAMESPACE_
namespace error
{
    const enum kError {
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
        StructError(std::string msg, kError type)
        {
            switch (type)
            {
            case kError::STACK:
                s = "Stack";
                break;
            case kError::QUEUE:
                s = "Queue";
                break;
            case kError::LIST:
                s = "List";
                break;
            case kError::TREE:
                s = "Tree";
                break;
            case kError::GRAPH:
                s = "Graph";
                break;
            case kError::VECTOR:
                s = "Vector";
                break;
            case kError::MATRIX:
                s = "Matrix";
                break;
            }
            this->msg = s + "Error:" + msg;
        }
    };
} /* namespace error */
#endif
#endif

#ifndef STRUCT_NAMESPACE_
#define STRUCT_NAMESPACE_
namespace Struct
{

    TEMPLATE(dT)
    class Node
    {
        dT data;
        Node<dT> *next, *pre;
        class type = dT;

    public:
        Node()
        {
            next = nullptr;
            pre = nullptr;
        }
        Node(nT data)
        {
            this->data = data;
            next = nullptr;
            pre = nullptr;
        }
        std::string string() const
        {
            return static_cast<std::string>(data);
        }
    };

    TEMPLATE(dT)
    class Stack
    {
        Node<dT> *head;
        ull len;

    public:
        Stack()
        {
            len = 0;
        }
        Stack(dT data)
        {
            len = 0;
            head->data = data;
        }
        Stack(dT *array)
        {
            head->data = array[0];
            Node<dT> *pre = head;
            for (ull index = 1, len = 0; index < length<dT><dT>(array); index++, len++)
            {
                Node<dT> *next = new Node<dT>(array[index]);
                next->next = pre;
                pre->pre = next;
                pre = next;
            }
            head = pre;
        }
        ~Stack()
        {
            Node<dT> *now = head;
            do
            {
                now = now->next;
                delete now->pre;
            } while (now->next != nullptr);
            delete now;
            delete len;
        }
        Stack operator=(const Stack<dT> &s)
        {
            len = s.len;
            head->data = s.head->data;
            Node<dT> *now = head, nows = s.head;
            while (nows->next)
            {
                now = now->next;
                nows = nows->next;
                if (now)
                {
                    now->data = nows->data;
                    continue;
                }
                now = Node<dT>(nows->data);
            }
        }
        Stack operator=(const dT *array)
        {
            len = length<dT>(array);
            Node<dT> *now = head;
            FORE(i, array)
            {
                if (now)
                {
                    now->data = array[i];
                    now = now->next;
                }
                else
                {
                    now = new Node(array[i]);
                    now = now->next;
                }
            }
        }
        void push(dT data)
        {
            Node<dT> *n = new Node<dT>(data);
            n->next = head;
            head->pre = n;
            ++len;
        }
        void pop()
        {
            Node<dT> *n = head;
            head = head->next;
            delete n;
            --len;
        }
        dT top() const
        {
            return head->data;
        }
        dT topPop()
        {
            dT data = this->top();
            this->pop();
            --len;
            return data;
        }
        dT popTop()
        {
            this->pop();
            --len;
            return this->top();
        }
        ull length() const
        {
            return len;
        }
        std::string string() const
        {
            std::string str;
            Node<dT> *now = head;
            while (now)
            {
                str << now->string();
                now = now->next;
            }
            return str;
        }
    }; /* class Stack */

    TEMPLATE(dT)
    class Queue
    {
        Node<dT> *head, *tail;
        ull len;

    public:
        Queue()
        {
            tail->next = head;
            head->pre = tail;
            len = 0;
        }
        Queue(dT data)
        {
            tail->data = data;
            tail = tail->pre;
            len = 0;
        }
        Queue(dT *array)
        {
            len = length<dT>(array);
            Node<dT> *now = tail, *pre = head;
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
        ~Queue()
        {
            Node<dT> *now = tail;
            while (now != nullptr)
            {
                now = now->next;
                delete now->pre;
            }
            delete now;
            delete len;
        }

        const Queue &operator=(const Queue &q);
        const Queue &operator=(const dT *array);
        std::string string() const
        {
            std::string str;
            Node<dT> *now = head;
            while (now)
            {
                str << now->string();
                now = now->pre;
            }
            return str;
        }
    }; /* class Queue */

    TEMPLATE(dT)
    class BidirectionalList;

    TEMPLATE(dT)
    class BidirectionalCircularList : public BidirectionalList
    {
    public:
    };

    TEMPLATE(dT)
    class BinaryTree
    {
        class Node
        {
            dT data;
            Node *left, *right;

        public:
            Node() : data(0), left(nullptr), right(nullptr) {}
            Node(dT data) : data(data), left(nullptr), right(nullptr) {}
        } * head;
        static void delete_node(Node *now)
        {
            if (now->left)
                delete_node(now->left);
            if (now->right)
                delete_node(now->right);
            delete now;
        }
        static void build_tree(Node *now, Node *bt)
        {
            now->data = bt->data;
            if (bt->left)
            {
                if (now->left)
                    build_tree(now->left, bt->left);
                else
                {
                    now->left = new Node();
                    build_tree(now->left, bt->left);
                }
            }
            if (bt->right)
            {
                if (now->right)
                    build_tree(now->right, bt->right);
                else
                {
                    now->right = new Node();
                    build_tree(now->right, bt->right);
                }
            }
        }

    public:
        BinaryTree() {}
        BinaryTree(dT data)
        {
            head->data = data;
        }
        BinaryTree(std::string types, dT *data)
        {
            if (types.length<dT>() != length<dT>(data))
            {
                return;
            }
            Node *now = head;
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
                        now->left = new Node(data[i]);
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
                        now->right = new Node(data[i]);
                        now = now->right;
                    }
                    break;
                default:
                    return;
                }
            }
        }
        ~BinaryTree()
        {
            delete_node(head);
        }
        BinaryTree &insert(std::string types, dT data)
        {
            Node *now = head;
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
                now = new Node(data);
            }
            return *this;
        }
        BinaryTree &insert(std::string types, BinaryTree<dT> bt)
        {
            Node *now = head;
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
            Node *now = head;
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
    }; /* class BinaryTree */

    SET_TYPE_TEMPLATE_TWO_NAME(class, dT, int, dim)
    class Tree : public BinaryTree
    {
    public:
    };

    TEMPLATE(dT)
    class Edge;

    TEMPLATE(dT)
    class Point;

    TEMPLATE_TWO_NAME(eT, pT)
    class Graph;
} /* namespace Struct */
#endif

#ifndef MATH_NAMESPACE_
#define MATH_NAMESPACE_
namespace Math
{
    TEMPLATE(eT)
    class Reduce
    {
        /****************
         * > a=Reduce<int>([](int a,int b){return a+b;});
         * > list={1,2,3};
         * > a(list); // 6
        ****************/
        eT (*func)(eT, eT);

    public:
        Reduce(eT (*func)(eT, eT))
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
    }; /* class Reduce */

    class Complex
    {
    public:
        double real, imaginary;
        Complex() {}
        Complex(double real = 0.0, double imaginary = 0.0)
        {
            this->real = real;
            this->imaginary = imaginary;
        }
        ~Complex() {}

        const Complex &operator=(const Complex &c)
        {
            real = c.real;
            imaginary = c.imaginary;
            return *this;
        }

        const double mod() const
        {
            return sqrt(real * real + imaginary * imaginary);
        }
        const Complex &conjugate() const
        {
            return Complex(real, -imaginary);
        }

        const Complex &operator+(const Complex &c) const
        {
            return Complex(real + c.real, imaginary + c.imaginary);
        }
        const Complex &operator-(const Complex &c) const
        {
            return Complex(real - c.real, imaginary - c.imaginary);
        }
        const Complex &operator*(const Complex &c) const
        {
            return Complex(real * c.real - imaginary * c.imaginary, real * c.imaginary + imaginary * c.real);
        }
        const Complex &operator/(const Complex &c) const
        {
            return Complex((real * c.real + imaginary * c.imaginary) / (c.real * c.real + c.imaginary * c.imaginary),
                           (imaginary * c.real - real * c.imaginary) / (c.real * c.real + c.imaginary * c.imaginary));
        }

        const Complex &operator+=(const Complex &c)
        {
            (*this) = (*this) + c;
            return *this;
        }
        const Complex &operator-=(const Complex &c)
        {
            (*this) = (*this) - c;
            return *this;
        }
        const Complex &operator*=(const Complex &c)
        {
            (*this) = (*this) * c;
            return *this;
        }
        const Complex &operator/=(const Complex &c)
        {
            (*this) = (*this) / c;
            return *this;
        }

        bool operator==(const Complex &c) const
        {
            return real == c.real && imaginary == c.imaginary;
        }
        bool operator!=(const Complex &c) const
        {
            return !((*this) == c);
        }
    }; /* class Complex */
    std::ostream &operator<<(std::ostream &out, const Complex &c)
    {
        out << c.real << (c.imaginary < 0 ? "-" : "+") << c.imaginary << "j";
        return out;
    }

    TEMPLATE(dT)
    class Vector;

    TEMPLATE(dT)
    class Matrix;

#ifndef MODEL_NAMESPACE_
#define MODEL_NAMESPACE_
    namespace Model
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
    } /* namespace Model */
#endif
} /* namespace Math */
#endif

#ifndef TYPE_NAMESPACE_
#define TYPE_NAMESPACE_
namespace Type
{
    class BigInteger
    {
        bool sign; /* true -> +  false -> - */
        ull digit;
        std::vector<ull> data;
        static const ull kMOD = 1000000000000000ULL;
        static const int kWIDTH = 15;
        static ull str_to_ull(std::string str)
        {
            ull ans = 0;
            FOR_RANGE(c, str)
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
                data.push_back(num % kMOD);
                num /= kMOD;
            }
            digit = data.size();
        }
        BigInteger(std::string str)
        {
            sign = (str[0] != '-');
            FOR_RANGE(c, str)
            if (c < '0' || c > '9')
                goto end;
            FOR_REVERSE_SET_STEP(i, str.length(), kWIDTH, kWIDTH)
            data.push_back(str_to_ull(str.substr(i - kWIDTH, kWIDTH)));
            if (str.length() % kWIDTH)
                data.push_back(str_to_ull(str.substr(0, str.length() % kWIDTH)));
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
            FOR_RANGE(d, b.data)
            data.push_back(d);
            return *this;
        }
        const BigInteger &operator=(ll num)
        {
            sign = (num >= 0);
            data.clear();
            while (num)
            {
                data.push_back(num % kMOD);
                num /= kMOD;
            }
            digit = data.size();
            return *this;
        }
        const BigInteger &operator=(std::string str)
        {
            sign = (str[0] != '-');
            data.clear();
            FOR_RANGE(c, str)
            if (c < '0' || c > '9')
                goto end;
            FOR_REVERSE_SET_STEP(i, str.length(), kWIDTH, kWIDTH)
            data.push_back(str_to_ull(str.substr(i - kWIDTH, kWIDTH)));
            if (str.length() % kWIDTH)
                data.push_back(str_to_ull(str.substr(0, str.length() % kWIDTH)));
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
            FOR_REVERSE(i, digit, 0)
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
                while (now < digit && data[now] + 1 >= kMOD)
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
                    data[now] += kMOD;
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
                            ans.data.push_back((b.data[i] + g) % kMOD);
                            g = (b.data[i] + g) / kMOD;
                        }
                        else if (i >= b.digit)
                        {
                            ans.data.push_back((data[i] + g) % kMOD);
                            g = (data[i] + g) / kMOD;
                        }
                        else
                        {
                            ans.data.push_back((data[i] + b.data[i] + g) % kMOD);
                            g = (data[i] + b.data[i] + g) / kMOD;
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
    std::ostream &operator<<(std::ostream &out, BigInteger &b);
    std::istream &operator>>(std::istream &in, BigInteger &b);

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
    std::ostream &operator<<(std::ostream &out, BigDecimal &b);
    std::istream &operator>>(std::istream &in, BigDecimal &b);
} /* namespace Type */
#endif /* TYPE_NAMESPACE_ */
#endif /* ALGORITHMS_H_ */
