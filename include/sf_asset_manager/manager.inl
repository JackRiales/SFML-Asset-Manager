/*
SFML Asset Manager Template Implementation Header
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

#include "manager.h"
using namespace sf::asset;

// =====

template <typename KEY, typename T>
Manager<KEY,T>::Manager()
{
    // Nothing
}

// =====

template <typename KEY, typename T>
Manager<KEY,T>::Manager( std::map<KEY,T> reloaded_bin )
{
    _rc.bin = reloaded_bin;
}

// =====

template <typename KEY, typename T>
bool Manager<KEY,T>::load(KEY key, std::string path)
{
    #ifdef _DEBUG_
    printf("Loading new asset to the bin from directory %s\n", path.c_str());
    #endif
    T new_item;
    if (!new_item.loadFromFile(path)) {
        #ifdef _DEBUG_
        printf("Failed to load new asset from directory %s\n", path.c_str());
        #endif
        return false;
    } else {
        set(key, new_item);
        return true;
    }
}

// =====

template <typename KEY, typename T>
template <typename SECONDARY>
bool Manager<KEY,T>::load(KEY key, std::string path, SECONDARY param)
{
    #ifdef _DEBUG_
    printf("Loading new asset to the bin from directory %s with second parameter\n", path.c_str());
    #endif
    T new_item;
    if (!new_item.loadFromFile(path, param)) {
        #ifdef _DEBUG_
        printf("Failed to load new asset from directory %s\n", path.c_str());
        #endif
        return false;
    } else {
        set(key, new_item);
        return true;
    }
}

// =====

template <typename KEY, typename T>
bool Manager<KEY,T>::remove(KEY key)
{
    #ifdef _DEBUG_
    printf("Attempting removal of item from asset bin.\n");
    #endif
    if (!key_exists(key)) {
        #ifdef _DEBUG_
        printf("Removal failed. Check key parameter.\n");
        #endif
        return false;
    } else {
        _rc.bin.erase(key);
    }
}

// =====

template <typename KEY, typename T>
bool Manager<KEY,T>::set(KEY key, T item)
{
    #ifdef _DEBUG_
    printf("Attempting set of an existing item to the asset bin.\n");
    #endif
    if (key_exists(key)) {
        #ifdef _DEBUG_
        printf("Set failed. Check key parameter.\n");
        #endif
        return false;
    } else {
        _rc.bin[key] = item;
        return true;
    }
}

// =====

template <typename KEY, typename T>
const T& Manager<KEY,T>::get(KEY key)
{
    if (key_exists(key)) {
        return _rc.bin[key];
    } else {
        #ifdef _DEBUG_
        printf("Get failed. Key does not exist.\n");
        #endif
        return *(new T());
    }
}

// =====

template <typename KEY, typename T>
bool Manager<KEY,T>::key_exists(KEY key) const
{
    return (_rc.bin.find(key) != _rc.bin.end());
}

// ===== BEGIN FILE IO IMPLEMENTATIONS ===== //

template <typename KEY, typename T>
bool Manager<KEY,T>::write_binary (std::ofstream& out)
{
    if (!out) {
        return false;
    } else {
        boost::archive::binary_oarchive ar(out);
        ar << _rc;
        return true;
    }
}

template <typename KEY, typename T>
bool Manager<KEY,T>::write_binary (std::string path)
{
    std::ofstream out(path, std::ios::out | std::ios::binary);
    return write_binary(out);
}

template <typename KEY, typename T>
bool Manager<KEY,T>::read_binary (std::ifstream& in)
{
    if (!in) {
        return false;
    } else {
        boost::archive::binary_iarchive ar(in);
        ar >> _rc;
        return true;
    }
}

template <typename KEY, typename T>
bool Manager<KEY,T>::read_binary (std::string path)
{
    std::ofstream in(path, std::ios::in | std::ios::binary);
    return write_binary(in);
}

// ===== END   FILE IO IMPLEMENTATIONS ===== //
