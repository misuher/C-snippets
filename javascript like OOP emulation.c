//using func pointers to emulate OOP, as an example make a String class:
//STRING.h
typedef struct String_Struct* String;

struct String_Struct
{
    char* value;
    char* (*get)(const void* self);
    void (*set)(const void* self, char* value);
    int (*length)(const void* self);
};

char* getString(const void* self);                     //getter
void setString(const void* self, char* value);   //setter
int lengthString(const void* self);                     //general method
String newString();                                           //constructor

//STRING.c
String newString()
{
    String self = (String)malloc(sizeof(struct String_Struct));

    self->get = &getString;
    self->set = &setString;
    self->length = &lengthString;

    self->set(self, "");

    return self;
}

char* getString(const void* self_obj)
{
    return ((String)self_obj)->value;
}

//////////////////////////////////////////INHERITANCE
//emulate inheritance, but without inherit the set method(to emulate it is private)
//as an example we made the class InmmutableString from String
typedef struct ImmutableString_Struct* ImmutableString;

struct ImmutableString_Struct
{
    String base;

    char* (*get)(const void* self);
    int (*length)(const void* self);
};

ImmutableString newImmutableString(const char* value);

ImmutableString newImmutableString(const char* value)
{
    ImmutableString self = (ImmutableString)malloc(sizeof(struct ImmutableString_Struct));

    self->base = newString();

    self->get = self->base->get;
    self->length = self->base->length;

    self->base->set(self->base, (char*)value);

    return self;
}

//////////////////////////////////////////POLYMORPHISM
