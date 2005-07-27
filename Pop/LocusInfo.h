/*
 * File LocusInfo.h
 * Author : Sylvain Gaillard <yragael2001@yahoo.fr>
 * Last modification : Thursday July 29 2004
 *
*/
/*
Copyright or � or Copr. CNRS, (November 17, 2004)


This software is a computer program whose purpose is to provide classes
for sequences analysis.

This software is governed by the CeCILL  license under French law and
abiding by the rules of distribution of free software.  You can  use, 
modify and/ or redistribute the software under the terms of the CeCILL
license as circulated by CEA, CNRS and INRIA at the following URL
"http://www.cecill.info". 

As a counterpart to the access to the source code and  rights to copy,
modify and redistribute granted by the license, users are provided only
with a limited warranty  and the software's author,  the holder of the
economic rights,  and the successive licensors  have only  limited
liability. 

In this respect, the user's attention is drawn to the risks associated
with loading,  using,  modifying and/or developing or reproducing the
software by the user in light of its specific status of free software,
that may mean  that it is complicated to manipulate,  and  that  also
therefore means  that it is reserved for developers  and  experienced
professionals having in-depth computer knowledge. Users are therefore
encouraged to load and test the software's suitability as regards their
requirements in conditions enabling the security of their systems and/or 
data to be ensured and,  more generally, to use and operate it in the 
same conditions as regards security. 

The fact that you are presently reading this means that you have had
knowledge of the CeCILL license and that you accept its terms.
*/
// Secured inclusion of header's file
#ifndef _LOCUSINFO_H_
#define _LOCUSINFO_H_

//From STL
#include <vector>
using namespace std;

// From local Popgenlib
#include "AlleleInfo.h"
#include "GeneralExceptions.h"

// From Utils
#include <Utils/Exceptions.h>

/**
 * @brief The LocusInfo class.
 *
 * This is an AlleleInfo container with additionnal data like a name,
 * the ploidy and some comments.
 */
class LocusInfo {
	public: // Constantes
		static unsigned int HAPLODIPLOID;
		static unsigned int HAPLOID;
		static unsigned int DIPLOID;
		
	public: // Constructors and destructor
		/**
		 * @brief Build a new LocusInfo object.
		 *
		 * @param name The name of the locus.
		 * @param ploidy The ploidy of the locus.
		 */
		LocusInfo(const string &name, const unsigned int ploidy = DIPLOID);

		/**
		 * @brief Copy constructor.
		 */
		LocusInfo(const LocusInfo & locus_info);

		/**
		 * @brief Destroy the LocusInfo.
		 */
		virtual ~LocusInfo();
		
	public: // Methodes
		/**
		 * @brief Get the name of the locus.
		 */
		string getName() const;

		/**
		 * @brief Get the ploidy of the locus.
		 *
		 * @return The ploidy as an unsigned integer.
		 */
		unsigned int getPloidy() const;
		
		/**
		 * @brief Add an AlleleInfo to the LocusInfo.
		 *
		 * @throw BadIdentifierException if the AlleleInfo's id already exists.
		 */
		void addAlleleInfo(const AlleleInfo &allele)
			throw (BadIdentifierException);

		/**
		 * @brief Retrieve an AlleleInfo object of the LocusInfo.
		 *
		 * @throw AlleleNotFoundException if the id is not found.
		 */
		AlleleInfo * getAlleleInfoById(const string & id) const
			throw (AlleleNotFoundException);

		/**
		 * @brief Retrieve an AlleleInfo object of the LocusInfo.
		 *
		 * @throw IndexOutOfBoundsException if key excedes the number of alleles.
		 */
		AlleleInfo * getAlleleInfoByKey(unsigned int key) const
			throw (IndexOutOfBoundsException);

		/**
		 * @brief Get the position of an AlleleInfo.
		 *
		 * @throw AlleleNotFoundException if the AlleleInfo's id is not found.
		 */
		unsigned int getAlleleInfoKey(const string & id) const
			throw (AlleleNotFoundException);
		
		/**
		 * @brief Get the number of alleles at this locus.
		 */
		unsigned int getNumberOfAlleles() const;

		/**
		 * @brief Delete all alleles from the locus.
		 */
		void clear();

	protected:
		string _name;
		unsigned int _ploidy;
		vector <AlleleInfo *> _alleles;
};

#endif // _LOCUSINFO_H_
