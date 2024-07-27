
#include<iostream>
#include"string.h"
#include<string>
#include<ctime>
#include"sha1.h"

using namespace std;


template<typename T>
class DoubleNode
{
public:
    T data;
    T* arr;
    T space;
    DoubleNode<T>* ptr;
    DoubleNode<T>* next;
    DoubleNode<T>* prev;

    DoubleNode()
    {
        data = 0;
        space = 0;
        arr = new int[space];
        for (T i = 0; i < space; i++)
            arr[i] = 0;
        next = NULL;
        ptr = NULL;
        prev = NULL;
    }

    DoubleNode(T a, T s)
    {
        data = a;
        space = s;
        arr = new int[space];
        for (T i = 0; i < space; i++)
            arr[i] = 0;
        next = NULL;
        ptr = NULL;
        prev = NULL;
    }
};
template<class U>
class RoutingTable
{
public:
    DoubleNode<U>* head;
    DoubleNode<U>* tail;

    RoutingTable()
    {
        head = NULL;
        tail = NULL;
    }

    void delete_all()
    {
        while (head != NULL && tail != NULL)
        {

            if (head != tail)
            {
                DoubleNode* temp = new DoubleNode();
                temp = tail;
                tail = temp->prev;
                temp->prev->next = NULL;
                temp->next = NULL;
                temp->prev = NULL;
                delete temp;
            }
            if (head == tail)
            {
                DoubleNode* cur = head;
                DoubleNode* pre = NULL;
                cur->prev = NULL;
                cur->next = NULL;
                head = NULL;
                tail = NULL;
                delete cur;
            }
        }

        if (head == NULL && tail == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }
        else
        {
            cout << "List is not Empty" << endl;
            return;
        }

    }

    void add_RT(U a, U s, U* arr, U t)
    {
        DoubleNode<U>* temp = new DoubleNode<U>(a, s);
        temp->arr = routingtable11(a, s, arr, t);

        if (head == NULL && tail == NULL)
            head = tail = temp;

        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    U* routingtable11(U p, U b, U* arr, U t)
    {
        //cout << endl << endl << t << endl << endl;
        //cout << p<<endl;
        //int an1[9] = { 1,4,9,11,14,18,20,21,28 };
        U* sum_mach;
        sum_mach = new int[1];

        U* sum_mach1;
        sum_mach1 = new int[1];

        sum_mach[1] = arr[t - 1];
        sum_mach1[1] = arr[t - t];


        U num = 0;
        U num1 = 0;
        U num2 = 0;
        bool flag = 0;
        bool con = 0;
        U ii = 0;
        U* arrr;
        arrr = new int[b];
        for (U i = 1; i <= b; i++)
        {

            num = i - 1;
            //cout <<"huh" <<num << endl;
            num = pow(2, num);
            //cout << num << endl;
            num1 = p + num;
            //cout << num1 << endl;
            if (num1 > 31)
            {
                U p = num1 - 32;
                num1 = p;
            }
            if (num1 > 31)
            {
                U p = num1 - 32;
                num1 = p;
            }

            for (U i = 0; i < t; i++)
            {
                // cout << "dddddddddddddddddddddddddddddd" << temp->key << endl;
                if (num1 <= arr[i] && flag == 0)
                {
                    num2 = arr[i];
                    flag = 1;
                }
                if (sum_mach[1] < num1 && flag == 0)
                {
                    num2 = sum_mach1[1];
                    flag = 1;
                }
                //temp = temp->next;
            }



            while (flag == 1 && ii < b)
            {
                arrr[ii] = num2;
                //cout << endl << i << " " << "arrrr////////////////////" << arrr[ii] << endl;
                ii++;
                flag = 0;
            }
        }


        // arr[i - 1] = num1;
         //cout << arr[i-1]<<endl;


        return arrr;
    }

    void display()
    {
    DoubleNode<U>* temp = head;  

    while (temp != nullptr)
    {
        for (int i = 0; i < 5; ++i)  
        {
            std::cout << temp->arr[i] << std::endl;
        }
        temp = temp->next;
        if (temp != nullptr) 
        {
            std::cout << std::endl << std::endl;
        }
    }
    }

};

template<typename T>
class avl_node {
public:
    avl_node<T>* left;
    T key;
    string value;
    string filename;
    T line_no;
    T height;
    avl_node<T>* right;

    avl_node()
    {
        key = 0;
        value = "";
        filename = "";
        line_no = 0;
        height = 0;
        left = NULL;
        right = NULL;
    }

    avl_node(T a, string val)
    {
        key = a;
        value = val;
        filename = "";
        line_no = 0;
        height = 0;
        left = NULL;
        right = NULL;
    }

    avl_node(T a)
    {
        key = a;
        value = "";
        filename = "";
        line_no = 0;
        height = 0;
        left = NULL;
        right = NULL;
    }

};

template<class U>
class AVL
{
private:




public:

    avl_node<U>* root;
    U ll;
    void inc_l()
    {
        ll++;
    }

    AVL() {
        this->root = NULL;
        ll = 0;

    }

    void tree_display(avl_node<U>* t)
    {
        if (t == NULL)
            return;
        cout << "[ Key:" << t->key << ", Value:" << t->value << ",Line Number:" << t->line_no << ",File Name:" << t->filename << " ]" << endl;
        tree_display(t->left);
        tree_display(t->right);
    }

    U calheight(avl_node<U>* p) {

        if (p->left && p->right) {
            if (p->left->height < p->right->height)
                return p->right->height + 1;
            else return  p->left->height + 1;
        }
        else if (p->left && p->right == NULL) {
            return p->left->height + 1;
        }
        else if (p->left == NULL && p->right) {
            return p->right->height + 1;
        }
        return 0;

    }

    U bf(avl_node<U>* n) {  //balan fact 
        if (n->left && n->right) {
            return n->left->height - n->right->height;
        }
        else if (n->left && n->right == NULL) {
            return n->left->height;
        }
        else if (n->left == NULL && n->right) {
            return -n->right->height;
        }
    }

    avl_node<U>* llrotation(avl_node<U>* n) {
        avl_node<U>* p;
        avl_node<U>* tp;
        p = n;
        tp = p->left;

        p->left = tp->right;
        tp->right = p;

        return tp;
    }


    avl_node<U>* rrrotation(avl_node<U>* n) {
        avl_node<U>* p;
        avl_node<U>* tp;
        p = n;
        tp = p->right;

        p->right = tp->left;
        tp->left = p;

        return tp;
    }


    avl_node<U>* rlrotation(avl_node<U>* n) {
        avl_node<U>* p;
        avl_node<U>* tp;
        avl_node<U>* tp2;
        p = n;
        tp = p->right;
        tp2 = p->right->left;

        p->right = tp2->left;
        tp->left = tp2->right;
        tp2->left = p;
        tp2->right = tp;

        return tp2;
    }

    avl_node<U>* lrrotation(avl_node<U>* n) {
        avl_node<U>* p;
        avl_node<U>* tp;
        avl_node<U>* tp2;
        p = n;
        tp = p->left;
        tp2 = p->left->right;

        p->left = tp2->right;
        tp->right = tp2->left;
        tp2->right = p;
        tp2->left = tp;

        return tp2;
    }

    avl_node<U>* insertt(U key, string v_s, U p)
    {
        return insert(this->root, key, v_s, p);
    }

    avl_node<U>* insert(avl_node<U>* r, U keyy, string v_s, U p) {
        string str = "";
        str += itoa(28);
        str += "-th machine.txt";


        if (r == NULL) {
            // cout << "dfdfdfdf" << endl;
            avl_node<U>* n;
            n = new  avl_node<U>(keyy, v_s);
            inc_l();
            n->line_no = ll;
            n->filename = str;
            //n->data = data;
            r = n;
            //r->left = r->right = NULL;
            r->height = 1;

            fstream file;
            string value_str = v_s;
            file.open(n->filename, ios::app);
            file << value_str;
            file << endl;

            //n->
            cout << "xscxscs" << n->line_no << endl;
            file.close();
            //inc_l();
            return r;
        }
        else {
            if (keyy < r->key)
            {
                r->left = insert(r->left, keyy, v_s, p);

            }
            else
            {
                r->right = insert(r->right, keyy, v_s, p);
            }
        }
        /* fstream file;
         string value_str = v_s;
         file.open("avl.txt", ios::app);
         file << value_str;
         file << endl;
         file.close();*/
        r->height = calheight(r);

        if (bf(r) == 2 && bf(r->left) == 1) {
            r = llrotation(r);
        }
        else if (bf(r) == -2 && bf(r->right) == -1) {
            r = rrrotation(r);
        }
        else if (bf(r) == -2 && bf(r->right) == 1) {
            r = rlrotation(r);
        }
        else if (bf(r) == 2 && bf(r->left) == -1) {
            r = lrrotation(r);
        }



        return r;

    }

    avl_node<U>* deleteNode(avl_node<U>* p, U data, U pp) {
        if (p == NULL) {
            cout << "node not found" << endl;
            return NULL;
        }

        if (p->left == NULL && p->right == NULL) {
            if (p == this->root)
                this->root = NULL;
            delete p;
            return NULL;
        }

        avl_node<U>* t;
        avl_node<U>* q;
        if (p->key < data) {
            p->right = deleteNode(p->right, data, pp);
        }
        else if (p->key > data) {
            p->left = deleteNode(p->left, data, pp);
        }
        else {
            if (p->left != NULL) {
                q = inpre(p->left);
                p->key = q->key;


                p->left = deleteNode(p->left, q->key, pp);
            }
            else {
                q = insuc(p->right);
                p->key = q->key;
                p->right = deleteNode(p->right, q->key, pp);
            }
        }

        if (bf(p) == 2 && bf(p->left) == 1) { p = llrotation(p); }
        else if (bf(p) == 2 && bf(p->left) == -1) { p = lrrotation(p); }
        else if (bf(p) == 2 && bf(p->left) == 0) { p = llrotation(p); }
        else if (bf(p) == -2 && bf(p->right) == -1) { p = rrrotation(p); }
        else if (bf(p) == -2 && bf(p->right) == 1) { p = rlrotation(p); }
        else if (bf(p) == -2 && bf(p->right) == 0) { p = llrotation(p); }


        return p;
    }


    bool see_preorder(avl_node<U>* t, U e) {
        bool fflaag = 0, fflaag1 = 0, fflaag2 = 0;
        if (t == NULL)
            return 0;

        if (t->key == e)
        {
            fflaag = 1;
        }

        fflaag1 = see_preorder(t->left, e);
        fflaag2 = see_preorder(t->right, e);
        if (fflaag1 == true || fflaag2 == true)
        {
            fflaag = true;
        }
        if (fflaag == 1)
            return 1;
        else
            return 0;
    }




    avl_node<U>* inpre(avl_node<U>* p) {
        while (p->right != NULL)
            p = p->right;
        return p;
    }

    avl_node<U>* insuc(avl_node<U>* p) {
        while (p->left != NULL)
            p = p->left;

        return p;
    }
    void inorder(avl_node<U>* t) {
        if (t == NULL)
            return;
        inorder(t->left);
        cout << t->key << " ";
        inorder(t->right);
    }
    void preorder(avl_node<U>* t) {
        if (t == NULL)
            return;
        cout << "scscscs" << t->key << " ";
        preorder(t->left);
        preorder(t->right);
    }

    /*int pppreorder(avl_node* t) {
        if (t == NULL)
            return;
        cout << t->key << " ";
        preorder(t->left);
        preorder(t->right);
    }*/


    void postorder(avl_node<U>* t) {
        if (t == NULL)
            return;
        postorder(t->left);
        postorder(t->right);
        cout << t->key << " ";
    }

    U se_preorder(avl_node<U>* t, U e) {
        bool fflaag = 0;
        int num = 0;
        if (t->key == e)
        {
            num = t->key;
            fflaag = 1;
        }
        cout << t->key << " ";
        preorder(t->left);
        preorder(t->right);

        if (fflaag == 1)
            return num;
        else
            return 0;
    }

    string se_preorder1(avl_node<U>* t, U e) {
        bool fflaag = 0;
        string a1 = "";
        string a2 = "";
        string num = "";
        //t
        if (t == NULL)
            return "aac";
        if (t->key == e)
        {
            num = t->value;
            fflaag = 1;
        }
        /*if (t->key > e)
        {

            num = t->left->value;
            fflaag = 1;
        }*/
        //cout << t->key << " ";
        a1 = se_preorder1(t->left, e);
        a2 = se_preorder1(t->right, e);
        if (a1 != "" && a2 != "")
            fflaag = 1;


        if (fflaag == 1)
            return num;
        else
            return "c";
    }

    string se_preorder11(avl_node<U>* t, U e) {
        bool fflaag = 0;
        string num = "";
        //t

        if (t->key == e)
        {
            num = t->value;
            fflaag = 1;
        }
        if (t->key > e)
        {

            num = t->left->value;
            fflaag = 1;
        }
        //cout << t->key << " ";


        if (fflaag == 1)
            return num;
        else
            return "c";
    }


    string retre(avl_node<U>* t, U e) {
        bool fflaag = 0;
        ///int tmpp = 1;
        bool filecont = 0;
        string read_var = "";
        string read_var1 = "ddd";
        avl_node<U>* tmp = new avl_node<U>();
        if (t->key == e)
        {
            tmp = t;
            //fflaag = 1;
        }
        //cout << t->key << " ";
        preorder(t->left);
        preorder(t->right);

        U num = tmp->line_no;

        cout << "sdsdsedewdfcw" << endl << num << endl;

        cout << "qwqwqwqwqwq" << endl << tmp->filename << endl;

        ifstream file;

        file.open(tmp->filename);

        for (U i = 1; filecont != true || !file.eof(); i++)
        {
            if (i == 1)
            {
                getline(file, read_var1);
                filecont = true;
            }
            else
                getline(file, read_var);

        }

        //while (!file.eof())
        //{
        //    /*while (tmpp != num)
        //    {
        //        getline(file, read_var);
        //    }
        //    if (tmpp == num)
        //    {
        //        getline(file, read_var1);
        //    }*/
        //    tmpp++;
        //}
        file.close();
        return read_var1;
    }

    string itoa(U a)
    {
        string ss = "";
        while (a)
        {
            U x = a % 10;
            a /= 10;
            char i = '0';
            i = i + x;
            ss = i + ss;
        }
        return ss;
    }

    string retre00(avl_node<U>* t, U e) {

        //int tmpp = 1;
        string read_var = "";
        string read_var1 = "";
        string read_var2 = "";
        if (t == NULL)
        {
            return "nothing here";
        }

        if (t->key == e)
        {
            cout << "Yh woh key ha jis ki file sy value read karani" << t->key << endl;
            string read_var3 = "";
            bool filecontrol = false;
            avl_node<U>* tmp = new avl_node<U>();
            tmp = t;
            //fflaag = 1;
            U num = tmp->line_no;
            cout << "Yh woh key ki line no. ha jis ki file sy value read karani" << num << endl;
            //cout << "sdsdsedewdfcw" << endl << num << endl;

            cout << "qwqwqwqwqwq" << endl << tmp->filename << endl;

            ifstream file;
            file.open(tmp->filename);

            for (U i = 1; filecontrol != true || !file.eof(); i++)
            {
                if (i == tmp->line_no)
                {
                    getline(file, read_var);
                    cout << "non-garbage:" << read_var << endl;
                    filecontrol = true;
                }
                else
                {
                    getline(file, read_var3);
                    cout << "garbage:" << read_var3 << endl;
                }
            }
            file.close();
            return read_var;
        }
        else
        {
            read_var1 = retre00(t->left, e);
            read_var2 = retre00(t->right, e);
            if (read_var1 != "nothing here" || read_var2 != "nothing here")
            {
                if (read_var1 != "nothing here" && read_var1 != "")
                {
                    read_var = read_var1;
                }
                if (read_var2 != "nothing here" && read_var2 != "")
                {
                    read_var = read_var2;
                }
            }

        }
        //cout << t->key << " ";
       /* preorder(t->left);
        preorder(t->right);*/

        return read_var;
    }

    ~AVL() {

    }
};
///////////////////////////////////////////

template<typename T>
class nodee
{
public:
    T key;
    T space;
    T* table;
    T* span;
    RoutingTable<T> r;
    AVL<T> t;
    nodee<T>* next;

    nodee()
    {
        key = 0;
        space = 0;
        table = new int[space];
        for (T i = 0; i < space; i++)
            table[i] = 0;
        span = new int[space];
        for (T i = 0; i < space; i++)
            span[i] = 0;
        next = NULL;
        //  r = NULL;
    }

    nodee(T a, T s)
    {
        key = a;
        space = s;
        table = new int[space];
        for (T i = 0; i < space; i++)
            table[i] = 0;
        span = new int[space];
        for (T i = 0; i < space; i++)
            span[i] = 0;
        next = NULL;
        //r = NULL;
    }
};

template<class U>
class machines
{
private:
    //nodee* head, * tail;
public:
    //RoutingTable r1;
    nodee<U>* head, * tail;
    U mach_no;

    machines()
    {
        head = NULL;
        tail = NULL;
        mach_no = 0;
    }

    void semach_no(U a)
    {
        mach_no = a;
    }

    U getmach_no()
    {
        return mach_no;
    }

    U ret_mach(U p)
    {
        bool flag = 0;
        bool flag1 = 0;
        U num = 0;
        U num1 = 0;
        nodee<U>* temp = new nodee<U>();
        temp = head;
        //cout << endl << "xcdsxdcfscsdc" << p << endl;
        do
        {
            if (temp->next->key == p)
            {
                flag = 1;
                flag1 = 1;
                num = temp->next->key;
                num1 = temp->key;
            }
            if (flag == 0)
                temp = temp->next;
        } while (temp != head && flag == 0);

        return num1;
    }

    U* for_rt(U ms)
    {

        bool flag1 = 0;
        U* num;
        num = new int[ms];
        U let = 0;
        nodee<U>* temp = new nodee<U>();
        temp = head;

        for (U i = 0; i < ms; i++)
        {
            num[i] = temp->key;
            temp = temp->next;
        }


        /*for (int i = 0;i < s;i++)
        {
            cout << num[i] << endl;
        }*/

        return num;
    }

    void mach_rt()
    {
        nodee<U>* tmp = new nodee<U>();
        tmp = head;


        for (U i = 0; i < mach_no; i++)
        {
            //cout <<endl<< tmp->space << endl;
            //num[i] = temp->key;
            tmp->r.add_RT(tmp->key, tmp->space, for_rt(mach_no), mach_no);
            tmp->table = tmp->r.routingtable11(tmp->key, tmp->space, for_rt(mach_no), mach_no);
            tmp = tmp->next;
        }


    }




    void add_machines(U n, U s)
    {
        nodee<U>* tmp = new nodee<U>(n, s);
        //cout << endl << "zqzqzqzzq" << s << endl;
        mach_no++;

        //tmp->t.
        //tmp->r->arr
        if (emptyy())
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;

        }
        tmp->next = head;
        //mach_rt();
    }

    bool emptyy()
    {
        return (head == NULL);
    }

    U sear(U p, U e)
    {
        bool flag = 0;
        U num = 0;
        U nnum1 = 0;
        nodee<U>* temp = new nodee<U>();
        temp = head;

        do
        {
            if (temp->key == p)
            {
                flag = 1;
                //flag1 = 1;
                num = temp->key;
            }
            if (flag == 0)
                temp = temp->next;
        } while (temp != head && flag == 0);


        nnum1 = temp->t.se_preorder(temp->t.root, e);

        if (flag == 1)
            return nnum1;
        else
            return 0;



    }

    string sear1(U p, U e)
    {
        bool flag = 0;
        U num = 0;
        string nnum1 = "";
        nodee<U>* temp = new nodee<U>();
        temp = head;

        do
        {
            if (temp->key == p)
            {
                flag = 1;
                //flag1 = 1;


                num = temp->key;
            }
            //if (flag == 0)
            temp = temp->next;
        } while (temp != head && flag == 0);


        nnum1 = temp->t.se_preorder1(temp->t.root, e);
        cout << "ghvhjbvjcfjhgvyt" << nnum1 << endl;

        /* if (flag == 1)
             return nnum1;
         else*/
        return "c";



    }



    void add_key(U p, U e, string str)
    {
        bool flag = 0;
        U num = 0;
        nodee<U>* temp = new nodee<U>();
        temp = head;

        do
        {
            if (temp->key == p)
            {
                flag = 1;
                num = temp->key;
            }
            temp = temp->next;
        } while (temp != head && flag == 0);


        temp->t.root = temp->t.insert(temp->t.root, e, str, p);


    }

    void del_key(U p, U e)
    {
        bool flag = 0;
        U num = 0;
        nodee<U>* temp = new nodee<U>();
        temp = head;

        do
        {
            if (temp->key == p)
            {
                flag = 1;
                num = temp->key;
            }
            temp = temp->next;
        } while (temp != head && flag == 0);


        temp->t.root = temp->t.deleteNode(temp->t.root, e, p);


    }

    void delete_s()
    {
        nodee<U>* cur = head;
        nodee<U>* pre = NULL;
        if (emptyy())
        {
            cout << "List is Empty" << endl;
            return;
        }
        else if (head == tail)
        {
            cur->next = NULL;
            head = NULL;
            tail = NULL;
            delete cur;
            return;
        }
        pre = tail;
        pre->next = cur->next;
        head = pre->next;
        cur->next = NULL;
        delete cur;
        return;
    }
    void delete_machine(U pos)
    {
        nodee<U>* cur = head;
        nodee<U>* pre = NULL;
        if (emptyy())
        {
            cout << "List is Empty" << endl;
            return;
        }
        if (pos == 1)
        {
            delete_s();
            return;
        }
        for (U i = 1; i < pos && cur->next != head; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        cur->next = NULL;
        delete cur;
        return;
    }

    void display()
    {
        nodee<U>* temp = new nodee<U>();
        temp = head;
        do
        {
            cout << temp->key << endl;
            temp = temp->next;
        } while (temp != head);
    }

    void disp_tree(U p)
    {
        bool flag = 0;
        U num = 0;
        nodee<U>* temp = new nodee<U>();
        temp = head;

        do
        {
            if (temp->key == p)
            {
                flag = 1;
                // flag1 = 1;
                num = temp->key;
            }
            if (flag == 0)
                temp = temp->next;
        } while (temp != head && flag == 0);

        temp->t.preorder(temp->t.root);
    }

    void routing_tab(U p, U b)
    {
        bool flag = 0;
        bool flag1 = 0;
        int num = 0;
        nodee<U>* temp = new nodee<U>();
        temp = head;

        do
        {
            if (temp->key == p)
            {
                flag = 1;
                flag1 = 1;
                num = temp->key;
            }
            if (flag == 0)
                temp = temp->next;
        } while (temp != head && flag == 0);

        for (U i = 0; i < b; i++)
        {
            cout << temp->table[i] << endl;
        }
    }

    void avl_display(U p)
    {
        bool flag = 0;
        U num = 0;
        nodee<U>* temp = new nodee<U>();
        temp = head;

        do
        {
            if (temp->key == p)
            {
                flag = 1;
                num = temp->key;
            }
            //if (flag == 0)
            temp = temp->next;
        } while (temp != head && flag == 0);

        temp->t.tree_display(temp->t.root);
    }



};

///////////////////////////////////////


/////////////////////////////////////////////////

template<typename T>
class hashh {

public:

    T space_b; //space
    T space_t;
    T mach_len;   //mach nos
    T* mach;      //mach keys

    machines<T> m1;
    RoutingTable<T> rr;


    hashh()
    {
        space_b = 0;
        space_t = 0;
        mach_len = 0;
        mach = new int[mach_len];
        for (int i = 0; i < mach_len; i++)
            mach[i] = 0;

    }

    hashh(T a, T c, T b)
    {
        space_t = a;

        space_b = c;
        mach_len = b;
        mach = new int[mach_len];
        for (T i = 0; i < mach_len; i++)
            mach[i] = 0;


    }


    void setspace_b(T a)
    {
        space_b = a;
    }

    T getspace_b()
    {
        return space_b;// = a;
    }

    void setspace_t(T a)
    {
        space_t = a;
    }

    int getspace_t()
    {
        return space_t;// = a;
    }


    void add_machines(T n)
    {
        string* let;
        let = new string[n];
        for (T i = 0; i < n; i++)
            let[i] = "";
        T* let1;
        let1 = new int[n];
        T* let21;
        let21 = new int[n];
        for (T i = 1; i <= n + 1; i++)
        {
            string no = "";
            //i--;

            cout << endl << "Enter machine Key;" << " " << i - 1 << endl;
            getline(cin, let[i - 1]);
            let1[i - 1] = Hash(let[i - 1]);
            //cin >> mach[i];



        }
        for (int i = 0; i < mach_len; i++)
            mach[i] = let1[i];      ///////////////////////////////////////////////////////////////////

            /*cout << endl << endl;
            for (int i = 0;i < n;i++)
            {
                cout << let[i] << endl;
            }*/
        mach = acsending(mach, n);
        /*for (int i = 0;i < n;i++)
        {
            cout << let[i] << endl;
        }*/

        /*for (int i = 0;i < mach_len;i++)
            mach[i] = let1[i];*/           /////////////////////////////////////////////////////

        for (T i = 0; i < n; i++)
        {
            //cout << let[i] << endl;
            m1.add_machines(mach[i], getspace_b());
            //rr.insert(let1[i], getspace());
        }
        m1.for_rt(mach_len);
        m1.mach_rt();
        cout << endl << endl;
        //m1.display();



        //m1.add_machines(let[);
    }

    void auto_add_machines(T n)
    {
        string* let;
        let = new string[n];
        for (T i = 0; i < n; i++)
            let[i] = "";
        T* let1;
        let1 = new int[n];
        T* let21;
        let21 = new int[n];
        for (T i = 0; i < n; i++)
        {
            T no = 0;
            //i--;

            srand(time(0));
            no = (rand() % getspace_t());
            // getline(cin, let[i-1]);
             //let1[i-1] = Hash(let[i-1]);
            mach[i] = no;



        }

        mach = acsending(mach, n);

        for (T i = 0; i < n; i++)
        {
            //cout << let[i] << endl;
            m1.add_machines(mach[i], getspace_b());
            //rr.insert(let1[i], getspace());
        }
        m1.for_rt(mach_len);
        m1.mach_rt();
        cout << endl << endl;
        //m1.display();



        //m1.add_machines(let[);
    }

    //int routingtable1(int p, int s)
    //{
    //    //cout << "Aa";
    //   // cout << "Aa";
    //    int num = 0;
    //    int num1 = 0;
    //    num = s - 1;

    //    num = pow(2, num);
    //    num1 = p + num;
    //    if (num1 > 31)
    //    {
    //        int p = num1 - 32;
    //        num1 = p;
    //    }

    //    return num1;
    //}

    void insert_key(T b, T t)      //int p, int e,
    {
        T p = 0;
        T m11 = 0;
        display_key();
        cout << "Enter machine id to enter from:" << endl;
        cin >> p;
        //m11 = machine_at_position(m);


        string hh = "";
        cout << "Enter Data key:" << endl;
        getline(cin, hh);

        //string hh1 = "";
        cout << "Enter Data key:" << endl;
        getline(cin, hh);

        T nh = 0;
        T nh1 = 0;
        nh = Hash(hh);
        cout << endl << endl;
        cout << nh << "dk" << endl;;


        string hh1 = "";
        cout << "Enter Data value:" << endl;
        getline(cin, hh1);

        cout << "Enter Data value:" << endl;
        getline(cin, hh1);
        //cin >> hh1;

        /*int nh1 = 0;
        int nh11 = 0;
        nh1 = Hash(hh1);
        cout << endl << endl;
        cout << nh1 << "dk" << endl;;*/


        p = look_up_RT(p, nh, b, t);
        // cout << endl << "jjjjj" << p << endl;

        m1.add_key(p, nh, hh1);
        //m1.add_key(p, e + 1, "Pepsi");
        //m1.add_key(p, e - 1, "cokacola");
        //m1.disp_tree(p);



    }

    void del_avl(T b, T t)
    {
        T p = 0;
        T m11 = 0;
        display_key();
        cout << "Enter machine id to enter from:" << endl;
        cin >> p;

        string hh = "";
        cout << "Enter Data key:" << endl;
        getline(cin, hh);

        //string hh1 = "";
        cout << "Enter Data key:" << endl;
        getline(cin, hh);

        T nh = 0;
        T nh1 = 0;
        nh = Hash(hh);
        cout << endl << endl;
        cout << nh << "dk" << endl;;

        p = look_up_RT(p, nh, b, t);

        m1.del_key(p, nh);
    }

    void retreive_key(T p, T e, T b, T t)
    {
        p = look_up_RT(p, e, b, t);
        // cout << endl << "jjjjj" << p << endl;

        m1.sear(p, e);


    }



    T routingtable1(T p, T b, T t)
    {
        //cout << "Aa";
        T y = 0;
        bool flag = 0;


        /*int arr[] = { 10,20,30,40,50,60 };
        int arrSize = sizeof(arr) / sizeof(arr[0]);*/
        nodee<T>* temp = new nodee<T>();
        temp = m1.head;
        //cout <<"asasasasasasasasasasasasasasasasasa"<< temp->key << endl;
        // cout << "Aa";
        T num = 0;
        T num1 = 0;
        T num2 = 0;
        num = b - 1;

        num = pow(2, num);
        num1 = p + num;
        if (num1 > (t - 1))
        {
            T p = num1 - t;
            num1 = p;
        }
        for (T i = 0; i < this->mach_len; i++)
        {
            // cout << "dddddddddddddddddddddddddddddd" << temp->key << endl;
            if (num1 <= temp->key && flag == 0)
            {
                num2 = temp->key;
                flag = 1;
            }
            if (m1.tail->key < num1 && flag == 0)
            {
                num2 = m1.head->key;
                flag = 1;
            }
            temp = temp->next;
        }

        return num2;
    }



    T look_up_RT(T p, T e, T b, T t)//p=call wla e=dhoond wla
    {
        //p=machine
        //e=key
        //s=space
        T first = 0;
        T second = 0;

        T n = 0;
        T tmp = 0;
        T z = 1;
        bool flag = 0;
        bool koi = 0;
        nodee<T>* temp = new nodee<T>();
        temp = m1.head;


        //cout << endl << p << " " << e << " " << n;
        while (koi == 0)
        {
            flag = 0;
            cout << endl << "xcscscscs" << p << " " << e << " " << b;
            if (p == e)
            {
                tmp = p;
                koi = 1;
            }
            //cout << p << endl;

            else if (p < e && e <= routingtable1(p, 1, t))
            {
                tmp = routingtable1(p, 1, t);
                //koi = 1;

            }


            else
            {
                int end = 0;
                for (int j = 1; j < b; j++)
                {
                    int n = routingtable1(p, j, t);
                    int l = routingtable1(p, j + 1, t);
                    cout << endl << n << "********************************" << l << endl;
                    if (routingtable1(p, j, t) < e && e <= routingtable1(p, j + 1, t))
                    {
                        //cout << "Aa3";
                        end = j;
                        flag = 1;
                        cout << endl << j << endl;
                    }
                }
                //tmp = routingtable1(p, end);//end;
                if (flag == 1)
                {
                    tmp = routingtable1(p, end, t);//end;
                }
                else
                {
                    tmp = routingtable1(p, b, t);
                }
                //koi = 1;
            }
            z++;
            p = tmp;
            //cout << p << endl;
            for (T i = 0; i < mach_len; i++)
            {
                if (p == temp->key)
                {
                    first = p;
                    second = temp->next->key;

                    for (T a = p + 1; a <= second; a++)
                    {
                        if (a == e)
                            koi = 1;
                    }
                }
                temp = temp->next;
            }




            /* if (p == 1)
             {
                 for (int i = 0;i < 5;i++)
                 {
                     if (nn1[i] == e)
                         koi = 1;
                 }
             }

             if (p == 4)
             {
                 for (int i = 0;i < 3;i++)
                 {
                     if (nn2[i] == e)
                         koi = 1;
                 }
             }


             if (p == 9)
             {
                 for (int i = 0;i < 5;i++)
                 {
                     if (nn3[i] == e)
                         koi = 1;
                 }
             }


             if (p == 11)
             {
                 for (int i = 0;i < 2;i++)
                 {
                     if (nn4[i] == e)
                         koi = 1;
                 }
             }

             if (p == 14)
             {
                 for (int i = 0;i < 3;i++)
                 {
                     if (nn5[i] == e)
                         koi = 1;
                 }
             }

             if (p == 18)
             {
                 for (int i = 0;i < 4;i++)
                 {
                     if (nn6[i] == e)
                         koi = 1;
                 }
             }

             if (p == 20)
             {
                 for (int i = 0;i < 2;i++)
                 {
                     if (nn7[i] == e)
                         koi = 1;
                 }
             }

             if (p == 21)
             {
                 for (int i = 0;i < 1;i++)
                 {
                     if (nn8[i] == e)
                         koi = 1;
                 }
             }

             if (p == 28)
             {
                 for (int i = 0;i < 7;i++)
                 {
                     if (nn9[i] == e)
                         koi = 1;
                 }
             }*/

        }
        return second;
        //return p;
    }


    /*int* machlist(int a)
    {
        nodee* tmp = new nodee();
        head = tmp;
        int* res;
        res = new int[]
            do
            {
                cout << tmp->key << endl;
                tmp = tmp->next;
            } while (tmp != head);

    }*/

    //
    //(int a,int d)  //a= call wla  d=search wla
    //{
    //    int num = getspace();
    //    int z = 0;
    //    int* let;
    //    let = new int[num];
    //    while (z != d)
    //    {
    //        let = rr.routingtable1(a, num);

    //    }

    //    


    //}


    T* acsending(T* arr, T size)
    {
        T temp = 0;
        for (T i = 0; i < size; i++)
        {
            for (T j = i + 1; j < size; j++)
            {
                //If there is a smaller element found on right of the array then swap it.
                if (arr[j] < arr[i])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;

                }
            }
        }
        return arr;
    }






    T Hash(string key) {
        T hash = 0;
        T index;

        for (int i = 0; i < key.length(); i++)
        {
            hash = hash + (int)key[i];
            //cout << "Hash = " << hash << endl;    //displays the hash function result
        }
        index = hash % space_t;

        //if(in)
        cout << "In = " << index << endl;
        return index;
    }

    T Hash_m(T key) {
        ; int hash11 = 0;
        int index;
        hash11 = key % space_t;


        cout << hash11;
        return key % space_t;

    }
    void print_RT(T b)
    {
        T p = 0;
        T m11 = 0;
        display_key();
        cout << "Enter machine id to enter from:" << endl;
        cin >> p;
        m1.routing_tab(p, b);
    }

    T machine_at_position(T a)
    {
        bool flag = 0;
        T n = 0;
        for (T i = 0; i < mach_len; i++)
        {
            if (mach[i] == a)
            {
                flag = 1;
                n = i + 1;
            }

        }
        if (flag)
            return n;
        else
            return 0;
    }

    void tree_display()
    {
        T p = 0;
        T m11 = 0;
        display_key();
        cout << "Enter machine id to enter from:" << endl;
        cin >> p;
        m1.avl_display(p);
    }

    T* rearrange(T* arr, T ml, T p)
    {
        T* temp;
        p--;
        temp = new int[ml - 1];

        for (T i = 0; i < p; i++)
            temp[i] = arr[i];

        for (T i = p + 1; i < ml; i++)
            temp[i - 1] = arr[i];

        return temp;
    }

    void del_tree()
    {

    }

    void del_machines()
    {

        T m = 0;
        T m11 = 0;
        T numm = 0;
        string numm1 = "";
        display_key();
        cout << "Enter machine id to remove:" << endl;
        cin >> m;
        m11 = machine_at_position(m);

        // cout << endl << "jijcdnvujdvjdnb" << m << "jijcdnvujdvjdnb" <<m1.ret_mach(m)<< endl;

        for (T i = m1.ret_mach(m); i <= m; i++)
        {
            // numm = m1.sear(m, i);
            numm1 = m1.sear1(m, i);

            /*if (numm != 0 && numm1!="c")
            {
                m1.add_key(m1.ret_mach(m), numm, numm1);
            }*/
            //cout << endl << "ssssssssssss" << endl << numm;

            //cout << endl << "ssssssssssss" << endl << numm1 << endl;
            cout << endl << "jijcdnvujdvjdnb" << i << endl;
        }
        //cout << endl << "jijcdnvujdvjdnb" << i << endl;




    //cout << endl << "ssssssssssss" << endl << machine_at_position(m);

    //m1.delete_machine(machine_at_position(m));

    //////////////
    //m1.display();

   // mach = rearrange(mach, mach_len, m11);
   // mach_len--;
    //m1.


    //display_key();


    }

    void join_machines()
    {

        T m = 0;
        T m11 = 0;
        T numm = 0;
        string numm1 = "";
        display_key();
        cout << "Enter machine id to join:" << endl;
        cin >> m;
        m11 = machine_at_position(m);

        // cout << endl << "jijcdnvujdvjdnb" << m << "jijcdnvujdvjdnb" <<m1.ret_mach(m)<< endl;

        for (int i = m1.ret_mach(m); i <= m; i++)
        {
            // numm = m1.sear(m, i);
            //numm1 = m1.sear1(m, i);

            /*if (numm != 0 && numm1!="c")
            {
                m1.add_key(m1.ret_mach(m), numm, numm1);
            }*/
            //cout << endl << "ssssssssssss" << endl << numm;

            //cout << endl << "ssssssssssss" << endl << numm1 << endl;
            //cout << endl << "jijcdnvujdvjdnb" << i << endl;
        }
        //cout << endl << "jijcdnvujdvjdnb" << i << endl;




    //cout << endl << "ssssssssssss" << endl << machine_at_position(m);

    //m1.delete_machine(machine_at_position(m));

    //////////////
    //m1.display();

   // mach = rearrange(mach, mach_len, m11);
   // mach_len--;
    //m1.


    //display_key();


    }

    void display_key()
    {
        for (T i = 0; i < mach_len; i++)
            cout << "machine no" << i + 1 << " " << mach[i] << endl;
    }

};
/////////////////////////////////////////////////
int calculatePower(int base, int powerRaised)
{
    if (powerRaised != 0)
        return (base * calculatePower(base, powerRaised - 1));
    else
        return 1;
}

int getPower(int base, int exponent) {
    /* Recursion termination condition,
     * Anything^0 = 1
     */
    if (exponent == 0) {
        return 1;
    }
    return base * getPower(base, exponent - 1);
}


////////////////////////////////////
int sha1_ftn(int nt,string value)
{
    std::string str_dec = "1987520";
    string let = "";
    let = sha1("price 40$,volume 20000");
    std::string::size_type sz;
    cout << "sha1('grape'):" << let << endl;
    long li_dec1 = std::stol(str_dec, &sz);
    cout << let << ": " << li_dec1 << endl;

    li_dec1 = li_dec1 % 127;
    cout << let << ": " << li_dec1 << endl;

    return 0;
}
//////////////////////////////////
int main()
{
    int n = 0;
    int nb = 0;
    int nt = 0;

    int choice = 0;









    //routingtable(4, 12, 5);
    

    cout << "Enter identifier space in bits;" << endl;
    cin >> nb;
    
    nt = calculatePower(2, nb);
    //cout <<endl<< n1<<" "<<n2;

    cout << "Enter no of machines:" << endl;
    cin >> n;
    hashh<int> h1(nt, nb, n);

    do
    {
        cout << "\t==============RING DHT MENU==============" << endl;
        cout << "\t0) EXIT              [PRESS 0]" << endl;
        cout << "\t1) Enter Machine ID  [PRESS 1]" << endl;
        cout << "\t2) Enter Data ID     [PRESS 2]" << endl;
        cout << "\t3) Remove Data ID    [PRESS 3]" << endl;
        cout << "\t4) Print RT          [PRESS 4]" << endl;
        cout << "\t5) Print Tree        [PRESS 5]" << endl;
        cout << "\t6) Join Key          [PRESS 6]" << endl;
        cout << "\t7) Remove Key        [PRESS 7]" << endl;
        cout << "\t8) Auto Enter Machine ID  [PRESS 8]" << endl;
        
        cout << endl << endl;

        cin >> choice;
        

        switch (choice)
        {
        case 0:
            return 0;
            break;

        case 1:
            h1.add_machines(n);
            break;

        case 2:
            h1.insert_key(nb, nt);
            
            cout << endl << endl;
            
            //h1.m1.disp_tree(18);
            break;

        case 3:
            h1.del_avl( nb, nt);
            break;

        case 5:
            h1.tree_display();
            break;

        case 4:
            h1.print_RT( nb);
            break;

        case 6:
            h1.auto_add_machines(n);
            break;

        case 8:
            h1.del_machines();
            break;



        }
    } while (choice);


    //hashh h1(n2,n1,n);
    //h1.add_machines(n);
    //h1.del_machines();
    //h1.insert_key(28, 3, nb,nt);
    //h1.insert_key(1, 27, 5);
    
    

    

    //avl_node* insert(avl_node * r, int keyy, string v_s, int p) {
     //   avl_node* insertt(int key, string v_s, int p)

    cout << endl << endl;

   
   // h1.m1.avl_display(4);
    //h1.retreive_key(1, 27, 5);

    //h1.display_key();

    //h1.del_machines();
    //cout << "hghghghg" << endl << h1.m1.sear1(4, 3);
    //h1.m1.disp_tree(4);

    //cout<<"hghghghg"<<endl<<h1.look_up_RT(28, 12, 5);
   // cout << "hghghghg" <<endl<< h1.look_up_RT(1, 26, 5);

    //h1.m1.routing_tab(14,nb);
    //h1.print_RT(14, nb);

   // h1.insert_key();
    //cout<<endl<<endl<<h1.look_up_RT(20, 21, 5);

    /*DoublyLinkedList d;
    d.setData();
    d.display();*/

   /* linkedlist r1;
    r1.insert_e(4, "Asim");
    r1.display();
   */

   /*a.root = a.insert(a.root, 27,"Asim1",28);
   a.root = a.insert(a.root, 28, "Asim2", 28);
   a.root = a.insert(a.root, 26, "Asim3", 28);
   a.root = a.insert(a.root, 25, "Asim4", 28);
   a.root = a.insert(a.root, 24, "Asim5", 28);
   a.root = a.insert(a.root, 23, "Asim6", 28);*/

    
   /*
   a.root = a.insert1(a.root, 27);
   a.root = a.insert1(a.root, 28);
   a.root = a.insert1(a.root, 26);
   a.root = a.insert1(a.root, 25);
   a.root = a.insert1(a.root, 24);
   a.root = a.insert1(a.root, 23);*/

    //return 0;

}





























//void AddItem(string d)
//{
//    int bucket = Hash(d);
//
//    if (HashTable[bucket]->d == "")
//    {
//        HashTable[bucket]->d = d;
//    }
//    else
//    {
//        item* Ptr = HashTable[bucket];
//        item* n = new item(d);
//
//        while (Ptr->next != NULL)
//        {
//            Ptr = Ptr->next;
//        }
//        Ptr->next;
//    }
//}
//
//
//int NumberOfItemsInBucket(int bucket)
//{
//    int slot = 0;
//    if (HashTable[bucket]->d == "")
//    {
//        return slot;
//    }
//    else
//    {
//        slot++;
//        item* Ptr = HashTable[bucket];
//        while (Ptr->next != NULL)
//        {
//            slot++;
//            Ptr = Ptr->next;
//        }
//    }
//    return slot;
//}


//class dhtn {
//public:
//    int k;
//    int v;
//
//    dhtn(int k, int v) {
//        this->k = k;
//        this->v = v;
//    }
//};
//
//
//
//class HashMapTable {
//private:
//    dhtn** t;
//    int T_S = 20;
//public:
//    HashMapTable() {
//        t = new dhtn * [20];
//        for (int i = 0; i < T_S; i++) {
//            t[i] = NULL;
//        }
//    }
//    int HashFunc(int k) {
//        return k % T_S;
//    }
//    void Insert(int k, int v) {
//        int h = HashFunc(k);
//        while (t[h] != NULL && t[h]->k != k) {
//            h = HashFunc(h + 1);
//        }
//        if (t[h] != NULL)
//            delete t[h];
//        t[h] = new dhtn(k, v);
//    }
//    int SearchKey(int k) {
//        int h = HashFunc(k);
//        while (t[h] != NULL && t[h]->k != k) {
//            h = HashFunc(h + 1);
//        }
//        if (t[h] == NULL)
//            return -1;
//        else
//            return t[h]->v;
//    }
//    void Remove(int k) {
//        int h = HashFunc(k);
//        while (t[h] != NULL) {
//            if (t[h]->k == k)
//                break;
//            h = HashFunc(h + 1);
//        }
//        if (t[h] == NULL) {
//            cout << "No Element found at key " << k << endl;
//            return;
//        }
//        else {
//            delete t[h];
//        }
//        cout << "Element Deleted" << endl;
//    }
//    ~HashMapTable() {
//
//    }
//};


