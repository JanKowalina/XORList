#include <iostream>
#include <cstring>

using namespace std;


typedef struct Cell {
    int val;
    Cell* Xor;
} Cell;

typedef struct Actual {
    Cell* act;
    Cell* next;
    Cell* prev;
} Actual;


Cell* XOR(Cell* First, Cell* Second) {
    return (Cell*)((uintptr_t)(First) ^ (uintptr_t)(Second));
}


void add_beg(Cell** beg, Cell** end, int val, Actual* actual);
void add_end(Cell** end, Cell** beg, int val, Actual* actual);
void add_act(Actual* actual, Cell** beg, int val);

void del_beg(Actual* actual, Cell** beg, Cell** end);
void del_end(Actual* actual, Cell** end, Cell** beg);
void del_act(Actual* actual, Cell** beg, Cell** end);
void del_val(Actual* actual, Cell** end, Cell** beg, int element);

void next(Actual* actual, Cell** beg);
void prev(Actual* actual, Cell** end);

void print(Cell** beg);

void deallocate(Cell** beg);


int main()
{
    char s[15];
    Cell* beg = NULL;
    Cell* end = NULL;
    Actual actual;
    actual.act = NULL;
    actual.next = NULL;
    actual.prev = NULL;
    int val;
    while (cin >> s) {

        if (strcmp(s, "ADD_BEG") == 0) {
            cin >> val;
            add_beg(&beg, &end, val, &actual);
        }
        else if (strcmp(s, "ADD_END") == 0) {
            cin >> val;
            add_end(&end, &beg, val, &actual);
        }
        else if (strcmp(s, "ADD_ACT") == 0) {
            cin >> val;
            add_act(&actual, &beg, val);
        }

        else if (strcmp(s, "DEL_BEG") == 0) {
            del_beg(&actual, &beg, &end);
        }
        else if (strcmp(s, "DEL_END") == 0) {
            del_end(&actual, &end, &beg);
        }
        else if (strcmp(s, "DEL_ACT") == 0) {
            del_act(&actual, &beg, &end);
        }
        else if (strcmp(s, "DEL_VAL") == 0) {
            cin >> val;
            del_val(&actual, &end, &beg, val);
        }

        else if (strcmp(s, "ACTUAL") == 0) {
            if (actual.act != NULL)
                cout << actual.act->val << endl;
            else
                cout << "NULL" << endl;
        }
        else if (strcmp(s, "NEXT") == 0) {
            next(&actual, &beg);
        }
        else if (strcmp(s, "PREV") == 0) {
            prev(&actual, &end);
        }

        else if (strcmp(s, "PRINT_FORWARD") == 0) {
            print(&beg);
        }
        else if (strcmp(s, "PRINT_BACKWARD") == 0) {
            print(&end);
        }
    }
    deallocate(&beg);
    return 0;
}


void add_beg(Cell** beg, Cell** end, int val, Actual* actual) {
    Cell* New_Cell = new Cell;
    New_Cell->val = val;
    New_Cell->Xor = *beg;
    if (*beg == NULL) {
        *beg = New_Cell;
        *end = New_Cell;
        actual->act = New_Cell;
    }
    else {
        (*beg)->Xor = XOR(New_Cell, (*beg)->Xor);
        *beg = New_Cell;
        if (XOR((*beg)->Xor, actual->act) == NULL) {
            actual->prev = *beg;
        }
    }
}

void add_end(Cell** end, Cell** beg, int val, Actual* actual) {
    Cell* New_Cell = new Cell;
    New_Cell->val = val;
    New_Cell->Xor = *end;
    if (*end == NULL) {
        *end = New_Cell;
        *beg = New_Cell;
        actual->act = New_Cell;
    }
    else {
        (*end)->Xor = XOR(New_Cell, (*end)->Xor);
        *end = New_Cell;
        if (XOR((*end)->Xor, actual->act) == NULL) {
            actual->next = *end;
        }
    }
}

void add_act(Actual* actual, Cell** beg, int val) {
    if (*beg != NULL) {
        Cell* New_Cell = new Cell;
        New_Cell->val = val;
        if (actual->prev == NULL) {
            add_beg(beg, beg, val, actual);
        }
        else {
            actual->prev->Xor = XOR(XOR(actual->prev->Xor, actual->act), New_Cell);
            New_Cell->Xor = XOR(actual->prev, actual->act);
            actual->act->Xor = XOR(New_Cell, actual->next);
            actual->prev = New_Cell;
        }
    }
}


void del_beg(Actual* actual, Cell** beg, Cell** end) {
    if (*beg != NULL) {
        if (XOR(*beg, *end) == NULL) {
            delete* beg;
            *beg = NULL;
            *end = NULL;
            actual->prev = NULL;
            actual->act = NULL;
            actual->next = NULL;
        }
        else {
            Cell* help = *beg;
            *beg = (*beg)->Xor;
            (*beg)->Xor = XOR((*beg)->Xor, help);
            if (XOR(actual->act, help) == NULL) {
                actual->act = *end;
                actual->next = NULL;
                actual->prev = actual->act->Xor;
            }
            else if (XOR(actual->prev, help) == NULL)
                actual->prev = NULL;

            delete help;
        }
    }
}

void del_end(Actual* actual, Cell** end, Cell** beg) {
    if (*beg != NULL) {
        if (XOR(*beg, *end) == NULL) {
            delete* beg;
            *beg = NULL;
            *end = NULL;
            actual->prev = NULL;
            actual->act = NULL;
            actual->next = NULL;
        }
        else {
            Cell* help = *end;
            *end = (*end)->Xor;
            if (XOR(actual->act, help) == NULL) {
                actual->act = actual->prev;
                actual->prev = XOR(actual->prev->Xor, help);
            }
            else if (XOR(actual->next, help) == NULL)
                actual->next = NULL;

            (*end)->Xor = XOR((*end)->Xor, help);
            delete help;
        }
    }
}

void del_act(Actual* actual, Cell** beg, Cell** end) {
    if (*beg != NULL) {
        if (XOR(actual->act, *beg) == NULL)
            del_beg(actual, beg, end);
        else if (XOR(actual->act, *end) == NULL)
            del_end(actual, end, beg);
        else {

            Cell* help = actual->act;
            actual->next->Xor = XOR(XOR(actual->next->Xor, actual->act), actual->prev);
            actual->prev->Xor = XOR(XOR(actual->prev->Xor, actual->act), actual->next);
            actual->act = actual->prev;
            actual->prev = XOR(actual->act->Xor, actual->next);
            delete help;
        }
    }
}

void del_val(Actual* actual, Cell** end, Cell** beg, int element) {
    if (*beg != NULL) {
        Cell* Previous = NULL;
        Cell* Current = *beg;
        Cell* Mover;
        Cell* Next;
        while (XOR(Current, *end) != NULL) {
            if (Current->val == element) {
                if (XOR(Current, *beg) == NULL) {
                    Current = XOR(Previous, Current->Xor);
                    del_beg(actual, beg, end);
                }
                else if (XOR(Current, actual->act) == NULL) {
                    Current = XOR(Previous, Current->Xor);
                    del_act(actual, beg, end);
                }
                else {
                    Previous->Xor = XOR(XOR(Previous->Xor, Current), XOR(Previous, Current->Xor));
                    Next = XOR(Previous, Current->Xor);
                    Next->Xor = XOR(XOR(Next->Xor, Current), XOR(Next, Current->Xor));
                    delete Current;
                    Current = Next;
                }
            }
            else {
                Mover = Current;
                Current = XOR(Previous, Current->Xor);
                Previous = Mover;
            }
        }
        if (Current->val == element)
            del_end(actual, end, beg);
    }
}

void next(Actual* actual, Cell** beg) {
    if (*beg != NULL) {
        if (actual->next == NULL && actual->prev == NULL) {
            cout << actual->act->val << endl;
        }
        else {
            if (actual->next == NULL) {
                actual->act = *beg;
                actual->prev = NULL;
                actual->next = actual->act->Xor;
                cout << actual->act->val << endl;
            }
            else {
                actual->prev = actual->act;
                actual->act = actual->next;
                actual->next = XOR(actual->act->Xor, actual->prev);
                cout << actual->act->val << endl;
            }
        }
    }
    else
        cout << "NULL" << endl;
}

void prev(Actual* actual, Cell** end) {
    if (*end != NULL) {
        if (actual->next == NULL && actual->prev == NULL) {
            cout << actual->act->val << endl;
        }
        else {
            if (actual->prev == NULL) {
                actual->act = *end;
                actual->next = NULL;
                actual->prev = actual->act->Xor;
                cout << actual->act->val << endl;
            }
            else {
                actual->next = actual->act;
                actual->act = actual->prev;
                actual->prev = XOR(actual->act->Xor, actual->next);
                cout << actual->act->val << endl;
            }
        }
    }
    else
        cout << "NULL" << endl;
}


void print(Cell** beg) {
    if (*beg != NULL) {
        Cell* Previous = NULL;
        Cell* Current = *beg;
        Cell* Mover;
        do {
            cout << Current->val << " ";
            Mover = Current;
            Current = XOR(Previous, Current->Xor);
            Previous = Mover;
        } while (Current != NULL);
        cout << endl;
    }
    else
        cout << "NULL" << endl;

}

void deallocate(Cell** beg) {
    if (*beg != NULL) {
        Cell* Dealloc1 = NULL;
        Cell* Dealloc2 = *beg;
        Cell* Dealloc3 = XOR(Dealloc1, Dealloc2->Xor);
        while (Dealloc3 != NULL) {
            if (Dealloc1 != NULL)
                delete Dealloc1;
            Dealloc1 = Dealloc2;
            Dealloc2 = Dealloc3;
            Dealloc3 = XOR(Dealloc1, Dealloc2->Xor);
        }
        if (Dealloc1 != NULL)
            delete Dealloc1;
        delete Dealloc2;
    }
}