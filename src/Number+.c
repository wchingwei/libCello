#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "Type+.h"
#include "Number+.h"

void add(var lhs, var rhs) {
  Num* inum = Type_Class(type_of(lhs), Num);
  assert(inum->add);
  inum->add(lhs, rhs);
}

void sub(var lhs, var rhs) {
  Num* inum = Type_Class(type_of(lhs), Num);
  assert(inum->sub);
  inum->sub(lhs, rhs);
}

void mul(var lhs, var rhs) {
  Num* inum = Type_Class(type_of(lhs), Num);
  assert(inum->mul);
  inum->mul(lhs, rhs);
}

void divide(var lhs, var rhs) {
  Num* inum = Type_Class(type_of(lhs), Num);
  assert(inum->div);
  inum->div(lhs, rhs);
}

void negate(var self) {
  Num* inum = Type_Class(type_of(self), Num);
  assert(inum->negate);
  inum->negate(self);
}

void absolute(var self) {
  Num* inum = Type_Class(type_of(self), Num);
  assert(inum->absolute);
  inum->absolute(self);
}

var Int = methods {
  methods_begin(Int),
  method(Int, New), 
  method(Int, Copy),
  method(Int, Eq), 
  method(Int, Ord),
  method(Int, Hash),
  method(Int, AsLong),
  method(Int, AsDouble),
  method(Int, Num),
  methods_end(Int)
};

var Int_New(var self, va_list* args) {
  IntData* io = cast(self, Int);
  io->value = va_arg(*args, int);
  return self;
}

var Int_Delete(var self) {
  return self;
}

var Int_Copy(var self) {
  IntData* io = cast(self, Int);
  return new(Int, io->value);
}

bool Int_Eq(var self, var other) {
  IntData* io = cast(self, Int);
  return io->value == as_long(other);
}

bool Int_Gt(var self, var other) {
  IntData* io = cast(self, Int);
  return io->value > as_long(other);
}

bool Int_Lt(var self, var other) {
  IntData* io = cast(self, Int);
  return io->value < as_long(other);
}

long Int_Hash(var self) {
  IntData* io = cast(self, Int);
  return io->value;
}

void Int_Add(var self, var other) {
  IntData* io = cast(self, Int);
  io->value += as_long(other);
}

void Int_Sub(var self, var other) {
  IntData* io = cast(self, Int);
  io->value -= as_long(other);
}

void Int_Mul(var self, var other) {
  IntData* io = cast(self, Int);
  io->value *= as_long(other);
}

void Int_Div(var self, var other) {
  IntData* io = cast(self, Int);
  io->value /= as_long(other);
}

void Int_Neg(var self) {
  IntData* io = cast(self, Int);
  io->value = - io->value;
}

void Int_Abs(var self) {
  IntData* io = cast(self, Int);
  io->value = abs(io->value);
}

long Int_AsLong(var self) {
  IntData* io = cast(self, Int);
  return io->value;
}

double Int_AsDouble(var self) {
  IntData* io = cast(self, Int);
  return io->value;
}

var Real = methods {
  methods_begin(Real),
  method(Real, New),
  method(Real, Copy),
  method(Real, Eq),
  method(Real, Ord),
  method(Real, Hash),
  method(Real, AsDouble),
  method(Real, AsLong), 
  method(Real, Num), 
  methods_end(Real)
};

var Real_New(var self, va_list* args) {
  RealData* ro = cast(self, Real);
  ro->value = va_arg(*args, double);
  return self;
}

var Real_Delete(var self) {
  return self;
}

var Real_Copy(var self) {
  RealData* ro = cast(self, Real);
  return new(Real, ro->value);
}

bool Real_Eq(var self, var other) {
  RealData* ro = cast(self, Real);
  return ro->value == as_double(other);
}

bool Real_Gt(var self, var other) {
  RealData* ro = cast(self, Real);
  return ro->value > as_double(other);
}

bool Real_Lt(var self, var other) {
  RealData* ro = cast(self, Real);
  return ro->value < as_double(other);
}

union interp_cast {
  double as_double;
  long as_long;
};

long Real_Hash(var self) {
  RealData* ro = cast(self, Real);
  union interp_cast ic;
  ic.as_double = ro->value;
  return ic.as_long;
}

void Real_Add(var self, var other) {
  RealData* ro = cast(self, Real);
  ro->value += as_double(other);
}

void Real_Sub(var self, var other) {
  RealData* ro = cast(self, Real);
  ro->value -= as_double(other);
}

void Real_Mul(var self, var other) {
  RealData* ro = cast(self, Real);
  ro->value *= as_double(other);
}

void Real_Div(var self, var other) {
  RealData* ro = cast(self, Real);
  ro->value /= as_double(other);
}

void Real_Neg(var self) {
  RealData* ro = cast(self, Real);
  ro->value = - ro->value;
}

void Real_Abs(var self) {
  RealData* ro = cast(self, Real);
  ro->value = fabs(ro->value);
}

double Real_AsDouble(var self) {
  RealData* ro = cast(self, Real);
  return ro->value;
}

long Real_AsLong(var self) {
  RealData* ro = cast(self, Real);
  return ro->value;
}