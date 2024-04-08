#include <iostream>
#include <vector>
#include <iomanip>

class NAryTreeNode {
private:
    int data;
    std::vector<NAryTreeNode*> children;

public:
    NAryTreeNode(int value, int numChildren) : data(value) {
        children.resize(numChildren, nullptr); // Initialize children array with nullptrs
    }

    // Set child at specified index
    void setChild(int childIndex, NAryTreeNode* childNode) {
        if (childIndex >= 0 && childIndex < children.size()) {
            children[childIndex] = childNode;
        }
    }

    //pointer to child at spec index
    NAryTreeNode* getChild(int childIndex) const {
        if (childIndex >= 0 && childIndex < children.size()) {
            return children[childIndex];
        };

        //nullptr if index is out of range
        std::cout << "Index out of range!" << std::endl;
        return nullptr; 
    }

    
    //getter
    int getData() const { return data; }
    //setter
    void setData(int value) { data = value; }

    const std::vector<NAryTreeNode*>& getChildren() const { return children; }

    // Function to add a new node as a child at a specified index
    void addNode(int childIndex, int newData, int numChildren) {
        if (childIndex >= 0 && childIndex < children.size()) {
            NAryTreeNode* newNode = new NAryTreeNode(newData, numChildren);
            children[childIndex] = newNode;
        }
    }
    void printTree(int level = 0) const {
        if (this) {
            std::cout << std::setw(level * 4) << "" << data << std::endl;
            for (NAryTreeNode* child : children) {
                if (child) {
                    child->printTree(level + 1);
                }
            }
        }
    }

    ~NAryTreeNode() {
        for (NAryTreeNode* child : children) {
            delete child;
        }
    }
};


int main() {
    // Create an N-ary tree with 3 children at each node
    NAryTreeNode* rootNode = new NAryTreeNode(1, 5);
    NAryTreeNode* child1 = new NAryTreeNode(2, 0);
    NAryTreeNode* child2 = new NAryTreeNode(3, 5);//creating another array of children for child 2
    NAryTreeNode* child3 = new NAryTreeNode(4, 0);
    NAryTreeNode* child4 = new NAryTreeNode(5, 5);//creating array of children for child 4
    NAryTreeNode* child5 = new NAryTreeNode(6, 0);
    NAryTreeNode* child6 = new NAryTreeNode(7, 0);


    //base children
    rootNode->setChild(0, child1);
    rootNode->setChild(1, child2);
    rootNode->setChild(2, child3);
    rootNode->setChild(3, child4);
    rootNode->setChild(4, child5);
    rootNode->setChild(5, child6);


    //create an array for the children of child 2
    NAryTreeNode* child2child1 = new NAryTreeNode(23, 0);
    NAryTreeNode* child2child2 = new NAryTreeNode(24, 0);
    NAryTreeNode* child2child3 = new NAryTreeNode(25, 0);
    NAryTreeNode* child2child4 = new NAryTreeNode(26, 0);
    NAryTreeNode* child2child5 = new NAryTreeNode(27, 0);

    child2->setChild(0, child2child1);
    child2->setChild(1, child2child2);
    child2->setChild(2, child2child3);
    child2->setChild(3, child2child4);
    child2->setChild(4, child2child5);

   
    NAryTreeNode* child4child1 = new NAryTreeNode(55, 0);
    NAryTreeNode* child4child2 = new NAryTreeNode(56, 0);
    NAryTreeNode* child4child3 = new NAryTreeNode(57, 0);
    NAryTreeNode* child4child4 = new NAryTreeNode(58, 0);
    NAryTreeNode* child4child5 = new NAryTreeNode(59, 0);

    child4->setChild(0, child4child1);
    child4->setChild(1, child4child2);
    child4->setChild(2, child4child3);
    child4->setChild(3, child4child4);
    child4->setChild(4, child4child5);


   
    rootNode->printTree();
   

 

    return 0;
};
