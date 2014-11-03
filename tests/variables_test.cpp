/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   V A R I A B L E S   T E S T   C L A S S                                                                    */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// Unit testing includes

#include "variables_test.h"


using namespace OpenNN;

// GENERAL CONSTRUCTOR

VariablesTest::VariablesTest(void) : UnitTesting()
{
}


// DESTRUCTOR

VariablesTest::~VariablesTest(void)
{
}


// METHODS


void VariablesTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Default constructor

   Variables v1;

   assert_true(v1.get_variables_number() == 0, LOG);
   assert_true(v1.count_inputs_number() == 0, LOG);
   assert_true(v1.count_targets_number() == 0, LOG);

   // Variables number constructor

   Variables v2(1);

   assert_true(v2.get_variables_number() == 1, LOG);
   assert_true(v2.count_inputs_number() == 0, LOG);
   assert_true(v2.count_targets_number() == 0, LOG);

   // XML constructor

   tinyxml2::XMLDocument* v1_document = v1.to_XML();

   Variables v3(*v1_document);

   assert_true(v3.get_variables_number() == 0, LOG);
   assert_true(v3.count_inputs_number() == 0, LOG);
   assert_true(v3.count_targets_number() == 0, LOG);

   // Copy constructor 

   Variables v5(1, 1);

   Variables v6(v5);

   assert_true(v6.get_variables_number() == 2, LOG);
   assert_true(v6.count_inputs_number() == 1, LOG);
   assert_true(v6.count_targets_number() == 1, LOG);
}


void VariablesTest::test_destructor(void)
{
   message += "test_destructor\n";

   Variables* vip = new Variables;

   delete vip;
}


void VariablesTest::test_assignment_operator(void)
{
   message += "test_assignment_operator\n";

   Variables v1(2);
   Variables v2 = v1;

   assert_true(v2.count_inputs_number() == 1, LOG);
   assert_true(v2.count_targets_number() == 1, LOG);
}


void VariablesTest::test_get_variables_number(void)
{
   message += "test_get_variables_number\n";

   Variables v;

   assert_true(v.get_variables_number() == 0, LOG);
}


void VariablesTest::test_count_inputs_number(void)
{
   message += "test_count_inputs_number\n";

   Variables v;

   assert_true(v.count_inputs_number() == 0, LOG);
}


void VariablesTest::test_count_targets_number(void)
{
   message += "test_count_targets_number\n";

   Variables v;

   assert_true(v.count_targets_number() == 0, LOG);
}


void VariablesTest::test_arrange_inputs_indices(void)
{
   message += "test_arrange_inputs_indices\n";

   Variables v;

   Vector<unsigned> inputs_indices = v.arrange_inputs_indices();

   assert_true(inputs_indices.size() == 0, LOG);
}


void VariablesTest::test_arrange_targets_indices(void)
{
   message += "test_arrange_targets_indices\n";

   Variables v;

   Vector<unsigned> targets_indices = v.arrange_targets_indices();

   assert_true(targets_indices.size() == 0, LOG);
}


void VariablesTest::test_arrange_names(void)
{
   message += "test_get_names\n";

   Variables v;

   Vector<std::string> names = v.arrange_names();

   assert_true(names.size() == 0, LOG);
}


void VariablesTest::test_get_name(void)
{
   message += "test_get_name\n";
}


void VariablesTest::test_arrange_inputs_name(void)
{
   message += "test_arrange_inputs_name\n";
}


void VariablesTest::test_arrange_targets_name(void)
{
   message += "test_arrange_targets_name\n";
}


void VariablesTest::test_arrange_units(void)
{
   message += "test_arrange_units\n";

   Variables v;

   Vector<std::string> units = v.arrange_units();

   assert_true(units.size() == 0, LOG);

}


void VariablesTest::test_get_unit(void)
{
   message += "test_get_unit\n";
}


void VariablesTest::test_arrange_inputs_units(void)
{
   message += "test_arrange_inputs_units\n";
}


void VariablesTest::test_arrange_targets_units(void)
{
   message += "test_arrange_targets_units\n";
}


void VariablesTest::test_arrange_descriptions(void)
{
   message += "test_arrange_descriptions\n";

   Variables v;

   Vector<std::string> descriptions = v.arrange_descriptions();

   assert_true(descriptions.size() == 0, LOG);

}


void VariablesTest::test_get_description(void)
{
   message += "test_get_description\n";
}


void VariablesTest::test_arrange_inputs_description(void)
{
   message += "test_arrange_inputs_description\n";
}


void VariablesTest::test_arrange_target_descriptions(void)
{
   message += "test_arrange_target_descriptions\n";
}



void VariablesTest::test_arrange_information(void)
{
   message += "test_arrange_information\n";

   Variables v(1);

   Matrix<std::string> information = v.arrange_information();

   unsigned rows_number = information.get_rows_number();
   unsigned columns_number = information.get_columns_number();

   assert_true(rows_number == 1, LOG);
   assert_true(columns_number == 4, LOG);
}


void VariablesTest::test_get_display(void)
{
   message += "test_get_display\n";

   Variables v;

   v.set_display(true);

   assert_true(v.get_display() == true, LOG);

   v.set_display(false);

   assert_true(v.get_display() == false, LOG);
}


void VariablesTest::test_set(void)
{
   message += "test_set\n";

   Variables v;

   // Instances and inputs and target variables

   v.set(1);

   assert_true(v.count_inputs_number() == 0, LOG);
   assert_true(v.count_targets_number() == 0, LOG);
}


void VariablesTest::test_set_variables_number(void)
{
   message += "test_set_variables_number\n";

   Variables v(1);

   v.set_variables_number(2);

   assert_true(v.get_variables_number() == 2, LOG);
}


void VariablesTest::test_set_input(void)
{
   message += "test_set_input\n";
}


void VariablesTest::test_set_target(void)
{
   message += "test_set_target\n";
}


void VariablesTest::test_set_names(void)
{
   message += "test_set_names\n";
}


void VariablesTest::test_set_name(void)
{
   message += "test_set_name\n";
}


void VariablesTest::test_set_units(void)
{
   message += "test_set_units\n";
}


void VariablesTest::test_set_unit(void)
{
   message += "test_set_unit\n";
}


void VariablesTest::test_set_descriptions(void)
{
   message += "test_set_descriptions\n";
}


void VariablesTest::test_set_description(void)
{
   message += "test_set_description\n";
}


void VariablesTest::test_set_display(void)
{
   message += "test_set_display\n";
}


void VariablesTest::test_to_XML(void)
{
   message += "test_to_XML\n";

   Variables v;
   
   tinyxml2::XMLDocument* document;

   // Test

   v.set(2);

   document = v.to_XML();

   assert_true(document != NULL, LOG);

   // Test

   v.set(2);

   v.set_use(0, Variables::Target);
   v.set_use(1, Variables::Input);

   document = v.to_XML();

   v.set();

   v.from_XML(*document);

   assert_true(v.get_variables_number() == 2, LOG);
   assert_true(v.get_use(0) == Variables::Target, LOG);
   assert_true(v.get_use(1) == Variables::Input, LOG);

}


void VariablesTest::test_from_XML(void)
{
   message += "test_from_XML\n";

   Variables v;

   // Test

   v.set(3);

   tinyxml2::XMLDocument* document = v.to_XML();

   v.from_XML(*document);
}


void VariablesTest::run_test_case(void)
{
   message += "Running variables test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Assignment operators methods

   test_assignment_operator();

   // Get methods

   test_get_variables_number();

   // Variables methods

   test_count_inputs_number();
   test_arrange_inputs_indices();

   test_count_targets_number();
   test_arrange_targets_indices();

   // Information methods

   test_arrange_names();
   test_get_name();

   test_arrange_inputs_name();
   test_arrange_targets_name();

   test_arrange_units();
   test_get_unit();

   test_arrange_inputs_units();
   test_arrange_targets_units();

   test_arrange_descriptions();
   test_get_description();

   test_arrange_inputs_description();
   test_arrange_target_descriptions();
 
   test_arrange_information();

   test_get_display();

   // Set methods

   test_set();

   // Variables methods

   test_set_input();
   test_set_target();

   // Information methods

   test_set_names();
   test_set_name();

   test_set_units();
   test_set_unit();

   test_set_descriptions();
   test_set_description();

   test_set_display();

   // Data methods

   test_set_variables_number();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   message += "End of variables test case.\n";
}


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2014 Roberto Lopez 
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

