// TODO: test

class RedBlackTree {
public:
    enum Color {
        kBlack = 0,
        kRed = 1
    };

    class Node {
    public:
        Node *parent, *left, *right;
        RedBlackTree::Color color;
        int val;

        Node(int value, RedBlackTree::Color col = RedBlackTree::Color::kBlack)
            : val {value}, color {col} { }
    };

    Node *root, *nil = new Node(0, RedBlackTree::Color::kBlack);

    Node* Min(Node* x) {
        while (x->left != nil) x = x->left;
        return x;
    }

    void LeftRotate(Node *x) {
        Node *y = x->right;
        x->right = y->left;

        if (y->left) y->left->parent = x;
        y->parent = x->parent;

        if (x->parent == nil) root = y;
        else if (x->parent->left == x) x->parent->left = y;
        else x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void RightRotate(Node *x) {
        Node *y = x->left;
        x->left = y->right;

        if (y->right) y->right->parent = x;
        y->parent = x->parent;
        
        if (x->parent == nil) root = y;
        else if (x->parent->left == x) x->parent->left = y;
        else x->parent->right = y;
        
        y->right = x;
        x->parent = y;
    }

    void Insert(Node *z) {
        Node *y = nullptr, *x = root;
        
        while (x != nil) {
            y = x;
            x = (z->val < x->val) ? x->left : x->right;
        }
        z->parent = y;

        if (y == nil) root = z;
        else if (z->val < y->val) y->left = z;
        else y->right = z;

        z->left = z->right = nullptr;
        z->color = Color::kRed;
        InsertFixup(z);
    }

    void InsertFixup(Node *z) {
        while (z->parent->color == Color::kRed) {
            if (z->parent == z->parent->parent->left) {
                Node *y = z->parent->parent->right;
                if (y->color == Color::kRed) {
                    z->parent->color = Color::kBlack;
                    y->color = Color::kBlack;
                    z->parent->parent->color = Color::kRed;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        LeftRotate(z);
                    }
                    z->parent->color = Color::kBlack;
                    z->parent->parent->color = Color::kRed;
                    RightRotate(z->parent->parent);
                }
            } else {

            }
        }
        root->color = Color::kBlack;
    }

    void Transplant(Node *u, Node *v) {
        if (u->parent == nil) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    void remove(Node *z) {
        Node *y = z, *x;
        Color color = y->color;
        if (z->left == nil) {
            x = z->right;
            Transplant(z, z->right);
        } else if (z->right == nil) {
            x = z->left;
            Transplant(z, z->left);
        } else {
            y = Min(z->right);
            color = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            } else {
                Transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            Transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        if (color == Color::kBlack) {
            DeleteFixup(x);
        }
    }

    void DeleteFixup(Node *x) {
        // TODO: implement
    }
};