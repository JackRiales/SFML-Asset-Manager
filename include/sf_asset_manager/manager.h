/*
SFML Asset Manager Template Class
Copyright (C) 2015  Jack Riales

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef SFML_ASSET_MANAGER_TEMPLATE
#define SFML_ASSET_MANAGER_TEMPLATE

// === Inclusion Macros === //
#include <iostream>                                 // -- cout and cin debug
#include <stdio.h>                                  // -- C Print
#include <fstream>                                  // -- File stream
#include <string>                                   // -- STL String
#include <sstream>                                  // -- String Stream
#include <map>                                      // -- STL Map
#include <boost/archive/binary_oarchive.hpp>        // -- Binary Write
#include <boost/archive/binary_iarchive.hpp>        // -- Binary Read
#include <boost/serialization/map.hpp>              // -- Serialization of STL Map
// ======================== //

namespace sf::asset
{

template <typename KEY, typename T>
class Manager
{
    public:
        /**
            \name Default Constructor
        */
        Manager();

        /**
            \name Constructor
            \brief Reloads in the given map
            \param Reloaded_Bin map to reload
        */
        Manager( std::map<KEY,T> reloaded_bin );

        /**
            \name Load
            \brief Loads a new SFML asset of type T from the given file path.
            \param Key key to map the asset under
            \param Path file path of the asset to load
            \return True asset loaded successfully into the system
            \return False Key already exists in the management bin
            \return False The file at the given path could not be loaded, or was not found.
        */
        bool load( KEY key, std::string path );

        /**
            \name Load w/ Second Parameter
            \brief Loads a new SFML asset of type T from the given file path and includes the given template item as a second load parameter
            \param Key key to map the asset under
            \param Path file path of the asset to load
            \param Param Parameter to pass into the SFML load function
            \return True asset loaded successfully into the system
            \return False Key already exists in the management bin
            \return False The file at the given path could not be loaded, or was not found.
        */
        template<typename SECONDARY>
        bool load ( KEY key, std::string path, SECONDARY param );

        /**
            \name Remove
            \brief Deletes the item at the given key from the asset bin
            \param Key key of item to remove
            \return True item was removed successfully
            \return False key was not yet in existence
            \return False item could not be removed
        */
        bool remove( KEY key );

        /**
            \name Set
            \brief Set a preexisting asset object to the given key
            \param Key new key to set item at
            \param Item existing item to set
            \return True item was successfully set to the file bin
            \return False key is already taken
        */
        bool set( KEY key, T item );

        /**
            \name Get
            \brief Get the item at the given key
            \param Key key of item to get
            \return T item at key
            \return Null key did not exist
        */
        const T& get( KEY key );

        /**
            \name Key Check
            \brief Returns if a given key exists
        */
        bool key_exists(KEY key) const;

        /**
            \name File IO Functions
            \brief Writes out or reads in a binary or sequential (xml formatted) file of the asset manager.
            \param fstream Stream to write the bin out to
            \param path Creates a new stream on the specified path and calls the corresponding stream function
            \return True IO successful
            \return False IO unsuccessful; reasons specified in debug
        */
        bool write_binary( std::ofstream& out );
        bool write_binary( std::string path );
        bool read_binary( std::ifstream& in );
        bool read_binary( std::string path );
        /** End File IO Function Headers */

    protected:
        /// Asset bin keeps object data under keys
        class serializable_map {
        public:
            std::map<KEY,T> bin;
        private:
            friend class boost::serialization::access;

            template<class Archive>
            void serialize(Archive & ar, const unsigned int version)
            {
                ar & bin;
            }
        } _rc;

    private:

};

}

// Implementation header
#include "manager.inl"

#endif
