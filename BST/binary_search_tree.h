#include <iostream>

using namespace std;

// Définition d'un nœud de l'arbre
struct Node {
    int data;          // Valeur stockée dans le nœud
    Node* left;        // Pointeur vers le sous-arbre gauche
    Node* right;       // Pointeur vers le sous-arbre droit

    // Constructeur
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Classe pour l'arbre binaire de recherche
class BinarySearchTree {
private:
    Node* root;        // Racine de l'arbre

    // Fonction récursive pour insérer un nœud
    Node* insertNode(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value); // Crée un nouveau nœud si l'emplacement est vide
        }
        if (value < node->data) {
            node->left = insertNode(node->left, value); // Insère dans le sous-arbre gauche
        } else if (value > node->data) {
            node->right = insertNode(node->right, value); // Insère dans le sous-arbre droit
        }
        return node;
    }

    // Fonction récursive pour rechercher un nœud
    bool searchNode(Node* node, int value) const {
        if (node == nullptr) {
            return false; // Valeur non trouvée
        }
        if (node->data == value) {
            return true; // Valeur trouvée
        } else if (value < node->data) {
            return searchNode(node->left, value); // Recherche dans le sous-arbre gauche
        } else {
            return searchNode(node->right, value); // Recherche dans le sous-arbre droit
        }
    }

    // Fonction récursive pour le parcours en ordre
    void inOrderTraversal(Node* node) const {
        if (node != nullptr) {
            inOrderTraversal(node->left);   // Parcourt le sous-arbre gauche
            cout << node->data << " ";     // Affiche la valeur du nœud
            inOrderTraversal(node->right); // Parcourt le sous-arbre droit
        }
    }

    // Fonction récursive pour libérer la mémoire
    void deleteTree(Node* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

public:
    // Constructeur
    BinarySearchTree() : root(nullptr) {}

    // Destructeur
    ~BinarySearchTree() {
        deleteTree(root); // Libère tous les nœuds
    }

    // Insérer une valeur dans l'arbre
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Rechercher une valeur dans l'arbre
    bool search(int value) const {
        return searchNode(root, value);
    }

    // Afficher les éléments en ordre croissant
    void inOrder() const {
        inOrderTraversal(root);
        cout << endl;
    }
};

// Programme principal
int main() {
    BinarySearchTree bst;

    // Insertion de valeurs dans l'arbre
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Parcours en ordre
    cout << "Parcours en ordre : ";
    bst.inOrder();

    // Recherche de valeurs
    cout << "Recherche de 40 : " << (bst.search(40) ? "Trouvé" : "Non trouvé") << endl;
    cout << "Recherche de 90 : " << (bst.search(90) ? "Trouvé" : "Non trouvé") << endl;

    return 0;
}
