/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   C R O S S   E N T R O P Y   E R R O R   T E S T   C L A S S   H E A D E R                                  */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/


#ifndef __CROSSENTROPYERRORTEST_H__
#define __CROSSENTROPYERRORTEST_H__

// OpenNN includes

#include "../unit_testing.h"

using namespace OpenNN;

class CrossEntropyErrorTest : public UnitTesting
{

#define	STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:

   // GENERAL CONSTRUCTOR

   explicit CrossEntropyErrorTest(void);


   // DESTRUCTOR

   virtual ~CrossEntropyErrorTest(void);


   // METHODS

   // Get methods

   // Set methods

   // Objective methods

   void test_calculate_evaluation(void);   
   void test_calculate_generalization_evaluation(void);

   void test_calculate_gradient(void);

   void test_calculate_Hessian(void);

   void test_to_XML(void);
   void test_from_XML(void);

   // Unit testing methods

   void run_test_case(void);
};

#endif


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2012 Roberto Lopez 
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
