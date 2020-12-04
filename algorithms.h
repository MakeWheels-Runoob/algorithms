/**
 * @file algorithms.h
 * @author Richard
 * @brief
 * @version 0.4
 * @date 2020-11-25
 * This header file contains many useful functions.
 * @copyright Copyright (c) 2020
 */
/****************************************************************************
 *                          A L G O R I H T M S . H                         *
 ****************************************************************************
 * unsigned long long length(dT *array): length of array
 * Struct::Stack: likely std::stack
 *   Struct::Stack::head: top of the stack
 *   Struct::Stack::len: length of the stack
 *   Struct::Stack::Stack(): Nothing
 *   Struct::Stack::Stack(dT data): Press data into the stack
 *   Struct::Stack::Stack(dT *array): Press the data in the array into the stack in turn
 *   const Stack<dT>& Struct::Stack::operator=(const Stack<dT> &s): Press the data in a stack into the stack in turn
 *   const Stack<dT>& Struct::Stack::operator=(const dT *array): Press the data in an array into this stack in turn
 *   void Struct::Stack::push(dT data): Press in a data to the stack
 *   void Struct::Stack::pop(): Pop up a data from the stack
 *   dT top(): Get the stack top data
 *   const unsigned long long Struct::Stack::length(): Gets the length of the stack
 *   const unsigned long long Struct::Stack::size(): Equivalent to Struct::Stack::length()
 *   bool Struct::Stack::empty(): Is the stack empty
 *   std::string toString(): Convert the stack to string form
 * Struct::Queue: likely std::queue
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

#define DEBUG
#ifdef DEBUG
#define LOG fprintf(stderr, "At function %s,line %d.\n", __FUNCTION__, __LINE__)
#else
#define LOG
#endif
#define TEMPLATE(name) template <class name>
#define TEMPLATE_TWO_NAME(name1, name2) template <class name1, class name2>
#define SET_TYPE_TEMPLATE(type, name) template <type name>
#define SET_TYPE_TEMPLATE_TWO_NAME(type1, name1, type2, name2) template <type1 name1, type2 name2>

#define FOR(i, s, e) for (auto(i) = (s); (i) < (e); ++(i))
#define FOR_SET_STEP(i, s, e, step) for (auto(i) = (s); (i) < (e); (i) += (step))
#define FOR_REVERSE(i, s, e) for (auto(i) = (s)-1; (i) >= (e); --(i))
#define FOR_REVERSE_SET_STEP(i, s, e, step) for (auto(i) = (s)-1; (i) >= (e); (i) -= (step))
#define FOR_RANGE(i, a) for (auto && (i) : (a))

TEMPLATE(dT)
inline uint64_t length(dT *array)
{
    return sizeof(array) / sizeof(dT);
}

TEMPLATE(dT)
inline dT sumOf(dT (*func)(int64_t), int64_t start, int64_t end, int64_t step)
{
    dT ans = new dT;
    FOR_SET_STEP(i, start, end, step)
    {
        ans = ans + (*func)(i);
    }
    return ans;
}

#ifdef DEBUG
#ifndef ERROR_NAMESPACE_
#define ERROR_NAMESPACE_
namespace Error
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
} // namespace Error
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
        std::string toString() const
        {
            return static_cast<std::string>(data);
        }
    };

    TEMPLATE(dT)
    class Stack
    {
        Node<dT> *head;
        uint64_t len;

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
            for (uint64_t index = 1, len = 0; index < length<dT><dT>(array); index++, len++)
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
        const Stack<dT> &operator=(const Stack<dT> &s)
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
        const Stack<dT> &operator=(const dT *array)
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

        const uint64_t length() const
        {
            return len;
        }
        const uint64_t size() const
        {
            return len;
        }
        bool empty() const
        {
            return len == 0;
        }

        const std::string toString() const
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
        uint64_t len;
        static inline void delete_from(Node<dT> *node)
        {
            Node<dT> *now = node;
            while (now)
            {
                now = now->pre;
                delete now->next;
            }
        }

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
            len = 1;
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

        const Queue &operator=(const Queue &q)
        {
            Node<dT> *now = this->head, *nowq = q.head;
            len = q.len;
            while (nowq)
            {
                if (now)
                {
                    now->data = nowq->data;
                }
                else
                {
                    now = new Node<dT>(nowq->data);
                }
                now = now->pre;
                nowq = nowq->pre;
            }
            delete_from(now);
            return *this;
        }
        const Queue &operator=(const dT *array)
        {
            Node<dT> *now = this->head;
            len = length<dT>(array);
            FOR(i, 0, len)
            {
                if (now)
                {
                    now->data = array[i];
                }
                else
                {
                    now = new Node<dT>(array[i]);
                }
                now = now->pre;
            }
            delete_from(now);
            return *this;
        }

        void push(dT data)
        {
            tail->data = data;
            tail = tail->pre;
            ++len;
        }
        void pop()
        {
            head = head->pre;
            delete head->next;
            --len;
        }
        const dT front() const
        {
            return head->pre->data;
        }
        const dT tail() const
        {
            return tail->next->data;
        }
        const uint64_t length() const
        {
            return len;
        }
        const uint64_t size() const
        {
            return len;
        }
        bool empty() const
        {
            return len == 0;
        }

        std::string toString() const
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
    class BidirectionalList
    {
        Node<dT> *head;
        uint64_t len;

    public:
        BidirectionalList();
        BidirectionalList(dT data);
        BidirectionalList(dT *data);
        ~BidirectionalList();
        BidirectionalList &insert(dT data, uint64_t where = 0);

        std::string toString();
    };

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
            Node() : left(nullptr), right(nullptr) {}
            Node(dT data) : data(data), left(nullptr), right(nullptr) {}
            ~Node()
            {
                delete data;
                left = nullptr;
                right = nullptr;
                delete left;
                delete right;
            }
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
                throw Error::StructError("LenError", Error::kError::TREE);
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

    SET_TYPE_TEMPLATE_TWO_NAME(class, dT, uint64_t, dim = 2)
    class Tree : public BinaryTree
    {
        class Node
        {
            dT data;
            Node *next[] = new Node[dim];

        public:
            Node()
            {
                FOR(i, 0, dim)
                next[i] = nullptr;
            }
            Node(dT data)
            {
                this->data = data;
                FOR(i, 0, dim)
                next[i] = nullptr;
            }
            ~Node()
            {
                delete data;
                FOR(i, 0, dim)
                next[i] = nullptr;
                delete next[i];
            }
        } * head;
        static void delete_node(Node *now)
        {
            FOR(i, 0, dim)
            {
                if (now->next[i])
                    delete_node(now->next[i]);
            }
            delete now;
        }
        static void build_tree(Node *now, Node *build, uint64_t dimb)
        {
            if (dimb > dim)
                throw Error::StructError("Trying to insert a tree whose dimension is larger than itself.", Error::kError::TREE);
            now->data = build->data;
            FOR(i, 0, dim)
            {
                if (i >= dimb)
                    continue;
                if (build->next[i])
                {
                    if (now->next[i])
                    {
                        build_tree(now->next[i], build->next[i], dimb);
                    }
                    else
                    {
                        now->next[i] = new Node();
                        build_tree(now->next[i], build->next[i], dimb);
                    }
                }
            }
        }

    public:
        Tree() {}
        Tree(dT data)
        {
            head->data = data;
        }
        Tree(uint64_t *types, dT *data)
        {
            if (length<uint64_t>(types) != length<dT>(data))
                throw Error::StructError("LenError", Error::kError::TREE);
            Node *now = head;
            FOR(i, 0, length<uint64_t>(types))
            {
                now->data = data[i];
                now->next[types[i]] = new Node();
                now = now->next[types[i]];
            }
        }
        ~Tree()
        {
            delete_node(head);
        }
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
    static const double kPI = acos(-1.0);

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
        Complex()
        {
            real = 0.0;
            imaginary = 0.0;
        }
        Complex(double real, double imaginary)
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
        const Complex &pow(uint64_t p)
        {
            Complex c = *this;
            while (--p)
                c *= (*this);
            return c;
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
    std::istream &operator>>(std::istream &in, Complex &c)
    {
        std::string str;
        in >> str;
        c.real = c.imaginary = 0;
        if (str[0] >= '0' && str[0] <= '9')
            c.real = str[0] - '0';
        uint64_t wherer = 1;
        for (; str[wherer] >= '0' && str[wherer] <= '9'; ++wherer)
        {
            c.real = c.real * 10 + str[wherer] - '0';
        }
        if (str[wherer] == '.')
        {
            uint64_t now = 10;
            for (++wherer; str[wherer] >= '0' && str[wherer] <= '9'; ++wherer)
            {
                c.real += (str[wherer] - '0') / now;
                now *= 10;
            }
        }
        if (str[0] == '-')
            c.real = -c.real;
        uint64_t wherei = wherer + 1;
        for (; str[wherei] >= '0' && str[wherei] <= '9'; ++wherei)
        {
            c.imaginary = c.imaginary * 10 + str[wherei] - '0';
        }
        if (str[wherei] == '.')
        {
            uint64_t now = 10;
            for (++wherei; str[wherei] >= '0' && str[wherei] <= '9'; ++wherei)
            {
                c.real += (str[wherei] - '0') / now;
                now *= 10;
            }
        }
        return in;
    }

    TEMPLATE(dT)
    class Vector;

    TEMPLATE(dT)
    class Matrix;

    TEMPLATE(dT = double)
    class Function
    {
        data[];
        uint64_t len;

    public:
        Function() : len(0) {}
        Function(dT data)
        {
            this->data = new dT[1];
            this->data[0] = data;
            len = 1;
        }
        Function(dT *data)
        {
            this->data = new dT[len = length<dT>(data)];
            FOR(i, 0, len)
            {
                this->data[i] = data[i];
            }
        }
        ~Function()
        {
            delete[] data;
            delete len;
        }
        const Function &operator=(const Function &func)
        {
            data = new dT[len = func.len];
            FOR(i, 0, len)
            {
                data[i] = func.data[i];
            }
            return *this;
        }
        const Function &operator=(dT *func)
        {
            data = new dT[len = length<dT>(func)];
            FOR(i, 0, len)
            {
                data[i] = func[i];
            }
            return *this;
        }
        Function &segment(uint64_t start, uint64_t end) const
        {
            dT data = new dT[end - start];
            FOR(i, start, end)
            {
                data[i] = this->data[i];
            }
            return Function(data);
        }
        const dT eval(dT x) const
        {
            if (len == 2)
            {
                return a[0] + a[1] * x;
            }
            else
            {
                Function<dT> func = segment(1, len);
                return a[0] + x * func.eval(x);
            }
        }
        const Function &operator+(const Function &func) const
        {
            Function<dT> ans = *this;
        }
    };
    class Fraction
    {
        double molecular;
        double denominator;

    public:
        Fraction(double mole = .0, double denom = .0) : molecular(mole), denominator(denom) {}
        ~Fraction() {}
        const Fraction &operator=(const Fraction &frac)
        {
            molecular = frac.molecular;
            denominator = frac.denominator;
            return *this;
        }
        const Fraction &operator=(const double &num)
        {
            molecular = num;
            return *this;
        }
        const Fraction &operator+(const Fraction &frac) const
        {
            return Fraction(molecular * frac.denominator + denominator * frac.molecular,
                            denominator * frac.denominator);
        }
        const Fraction &operator-(const Fraction &frac) const
        {
            return Fraction(molecular * frac.denominator - denominator * frac.molecular,
                            denominator * frac.denominator);
        }
        const Fraction &operator*(const Fraction &frac) const{
            return Fraction(molecular * frac.molecular,
                            denominator * frac.denominator);
        }
        const Fraction &operator/(const Fraction &frac) const{
            return Fraction(molecular * frac.denominator,
                            denominator * frac.molecular);
        }

        const Fraction &operator+(const double &num) const
        {
            return Fraction(molecular + denominator * num,
                            denominator);
        }
        const Fraction &operator-(const double &num) const
        {
            return Fraction(molecular - denominator * num,
                            denominator);
        }
        const Fraction &operator*(const double &num) const
        {
            return Fraction(molecular * num,
                            denominator);
        }
        const Fraction &operator/(const double &num) const{
            return Fraction(molecular,
                            denominator * num);
        }
    };

#ifndef MODEL_NAMESPACE_
#define MODEL_NAMESPACE_
    namespace Model
    {
#define VMODEL(name) class name##VirusModel
        VMODEL()
        {
        protected:
            uint64_t susceptible;
            uint64_t exposed;
            uint64_t infectious;
            uint64_t removed;
            double StoE;
            double StoI;
            double EtoI;
            double EtoR;
            double ItoR;
            double RtoS;
            VirusModel();
            virtual void next(uint64_t step = 1);
            virtual void print(FILE *file = stdout);
        }; /* class VirusModel */

        VMODEL(SI) : public VirusModel
        {
            uint64_t susceptible;
            uint64_t infectious;
            double StoI;

        public:
            SIVirusModel(uint64_t s = 100, uint64_t i = 1, double stoi = 0.5)
            {
                susceptible = s;
                infectious = i;
                StoI = stoi;
            }
            void next(uint64_t step = 1)
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
            uint64_t susceptible;
            uint64_t infectious;
            double StoI;
            double ItoS;

        public:
            SISVirusModel(uint64_t s = 100, uint64_t i = 1, double stoi = 0.5, double itos = 0.5)
            {
                susceptible = s;
                infectious = i;
                StoI = stoi;
                ItoS = itos;
            }
            void next(uint64_t step = 1)
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
            uint64_t susceptible;
            uint64_t infectious;
            uint64_t removed;
            double StoI;
            double ItoR;

        public:
            SIRVirusModel(uint64_t s = 100, uint64_t i = 1, uint64_t r = 0, double stoi = 0.5, double itor = 0.5)
            {
                susceptible = s;
                infectious = i;
                removed = r;
                StoI = stoi;
                ItoR = itor;
            }
            void next(uint64_t step = 1)
            {
                while (step--)
                {
                    susceptible += -StoI * susceptible * infectious;
                    infectious += StoI * susceptible * infectious - ItoR * infectious;
                    removed += ItoR * infectious;
                }
            }
            void print(FILE *file = stdout)
            {
                fprintf(file, "Susceptible:%d,Infectious:%d,Removed:%d\n", susceptible, infectious, removed);
                fprintf(file, "ratio of from susceptible to infectious:%f\n", StoI);
                fprintf(file, "ratio of from infectious to removed:%f\n", ItoR);
            }
        };
        VMODEL(SIRS)
        {
            uint64_t susceptible;
            uint64_t infectious;
            uint64_t removed;

            double StoI;
            double ItoR;
            double RtoS;

        public:
            SIRSVirusModel(uint64_t s = 100, uint64_t i = 1, uint64_t r = 0, double stoi = 0.5, double itor = 0.5, double rtos = 0.5)
            {
                susceptible = s;
                infectious = i;
                removed = r;
                StoI = stoi;
                ItoR = itor;
                RtoS = rtos;
            }
            void next(uint64_t step = 1)
            {
                while (step--)
                {
                    susceptible += RtoS * removed - StoI * susceptible * infectious;
                    infectious += StoI * susceptible * infectious - ItoR * infectious;
                    removed += ItoR * infectious - RtoS * removed;
                }
            }
            void print(FILE *file = stdout)
            {
                fprintf(file, "Susceptible:%d,Infectious:%d,Removed:%d\n", susceptible, infectious, removed);
                fprintf(file, "ratio of from susceptible to infectious:%f\n", StoI);
                fprintf(file, "ratio of from infectious to removed:%f\n", ItoR);
                fprintf(file, "ratio of from removed to susceptible:%f\n", RtoS);
            }
        };
    } /* namespace Model */
#endif
    void FFT(Complex *a, uint64_t lim, bool inverse = false)
    {
        uint64_t n = length<Complex>(a);
        uint64_t len;
        while (lim <= n)
            lim <<= 1, ++len;
        uint64_t rev[lim] = {0};
        FOR(i, 0, lim)
        {
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (len - 1));
        }
        FOR(i, 0, lim)
        {
            if (i < rev[i])
                std::swap(a[i], a[rev[i]]);
        }
        FOR(dep, 1, log2(lim) + 1)
        {
            uint64_t m = 1 << dep;
            Complex wn = Complex(cos(2.0 * Math::kPI / m),
                                 (inverse ? -1 : 1) * sin(2.0 * Math::kPI / m));
            FOR_SET_STEP(k, 0, lim, m)
            {
                Complex w = Complex(1.0, 0.0);
                FOR(j, 0, m >> 1)
                {
                    Complex t = w * a[k + j + (m >> 1)];
                    Complex u = a[k + j];
                    a[k + j] = u + t;
                    a[k + j + (m >> 1)] = u - t;
                    w *= wn;
                }
            }
        }
        if (inverse)
        {
            FOR(i, 0, lim)
            {
                a[i].real /= lim;
            }
        }
    }
    uint64_t gcd(uint64_t m, uint64_t n)
    {
        return m ? gcd(n, m % n) : n;
    }
    uint64_t lcm(uint64_t m, uint64_t n)
    {
        return m / gcd(m, n) * n;
    }
} /* namespace Math */
#endif

#ifndef TYPE_NAMESPACE_
#define TYPE_NAMESPACE_
namespace Type
{
    class BigInteger
    {
        bool sign; /* true -> +  false -> - */
        uint64_t digit;
        std::vector<uint64_t> data;
        static const uint64_t kMOD = 1000000000000000ULL;
        static const int kWIDTH = 15;
        static uint64_t str_to_ull(std::string str)
        {
            uint64_t ans = 0;
            FOR_RANGE(c, str)
            ans = ans * 10 + c - '0';
            return ans;
        }

    public:
        BigInteger() { digit = 0; }
        BigInteger(int64_t num)
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
            do
            {
                sign = (str[0] != '-');
                FOR_RANGE(c, str)
                if (c < '0' || c > '9')
                    break;
                FOR_REVERSE_SET_STEP(i, str.length(), kWIDTH, kWIDTH)
                data.push_back(str_to_ull(str.substr(i - kWIDTH, kWIDTH)));
                if (str.length() % kWIDTH)
                    data.push_back(str_to_ull(str.substr(0, str.length() % kWIDTH)));
            } while (false);
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
        const BigInteger &operator=(int64_t num)
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
            do
            {
                sign = (str[0] != '-');
                FOR_RANGE(c, str)
                {
                    if (c < '0' || c > '9')
                        break;
                }
                FOR_REVERSE_SET_STEP(i, str.length(), kWIDTH, kWIDTH)
                {
                    data.push_back(str_to_ull(str.substr(i - kWIDTH, kWIDTH)));
                    if (str.length() % kWIDTH)
                        data.push_back(str_to_ull(str.substr(0, str.length() % kWIDTH)));
                }
            } while (false);
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
                uint64_t now = 0;
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
                uint64_t now = 0;
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
            uint64_t g = 0;
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
        uint64_t digit;
        uint64_t decimalDigit;
        std::vector<uint64_t> data;
        std::vector<uint64_t> d_data;
        static const uint64_t kMOD = 1000000000000000ULL;
        static const int kWIDTH = 15;
        static const long double kMOD_OF_DECIMAL = 0.;
    }; /* class BigDecimal */
    std::ostream &operator<<(std::ostream &out, BigDecimal &b);
    std::istream &operator>>(std::istream &in, BigDecimal &b);
} /* namespace Type */
#endif /* TYPE_NAMESPACE_ */
#endif /* ALGORITHMS_H_ */
