/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* new_head = new PolyNode();
        PolyNode* cur = new_head;

        while (poly1 != nullptr || poly2 != nullptr){
            if (poly1 == nullptr){
                cur->next = poly2;
                break;
            }else if (poly2 == nullptr){
                cur->next = poly1;
                break;
            }

            if (poly1->power > poly2->power){
                PolyNode* tmp = poly1;
                poly1 = poly1->next;
                cur->next = tmp;
                cur = cur->next;
                cur->next = nullptr;
            }else if (poly1->power < poly2->power){
                PolyNode* tmp = poly2;
                poly2 = poly2->next;
                cur->next = tmp;
                cur = cur->next;
                cur->next = nullptr;
            }else {
                if (poly1->coefficient + poly2->coefficient != 0){
                    PolyNode* tmp = poly1;
                    poly1 = poly1->next;
                    tmp->next = nullptr;
                    tmp->coefficient += poly2->coefficient;
                    poly2 = poly2->next;
                    cur->next = tmp;
                    cur = cur->next;
                }else {
                    poly1 = poly1->next;
                    poly2 = poly2->next;
                }
            }
        }

        return new_head->next;
    }
};