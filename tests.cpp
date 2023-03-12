#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include "List.h"
#include "OList.h"

TEST_CASE("insert(value)"){
	OList *o = new OList();
	o->insert("5");
	CHECK(o->toString()=="5-->nullptr");
	o->insert("2");
	CHECK(o->toString()=="2-->5-->nullptr");
	o->insert("11");
	CHECK(o->toString()=="2-->5-->11-->nullptr");
}

TEST_CASE("contains(value)"){
	OList *o = new OList();
	o->insert("5");
	CHECK(o->contains("5")==true);
	o->insert("2");
	CHECK(o->contains("2")==true);
	o->insert("11");
	CHECK(o->contains("11")==true);
	
	//remove index 0, which is the value 2
	o->remove(0);
	CHECK(o->contains("2")==false);
}

TEST_CASE("get(loc)"){
	OList *o = new OList();
	o->insert("5");
	CHECK(o->get(0)=="5");
	o->insert("2");
	CHECK(o->get(1)=="5");
	CHECK(o->get(0)=="2");
	o->insert("4");
	CHECK(o->get(0)=="2");
	CHECK(o->get(1)=="4");
	CHECK(o->get(2)=="5");
}

TEST_CASE("remove(loc)"){
	OList *o = new OList();
	o->insert("5");
	o->insert("2");
	o->insert("4");
	CHECK(o->contains("4")==true);
	o->remove(1);
	CHECK(o->contains("4")==false);
	CHECK(o->get(1)=="5");
}

TEST_CASE("reverse()"){
	OList *o = new OList();
	o->insert("5");
	o->insert("2");
	o->insert("4");
	o->insert("11");
	CHECK(o->toString()=="2-->4-->5-->11-->nullptr");
	o->reverse();
	CHECK(o->toString()=="11-->5-->4-->2-->nullptr");
	o->reverse();
	CHECK(o->toString()=="2-->4-->5-->11-->nullptr");
	
}
