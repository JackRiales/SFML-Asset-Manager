LICENSE
--------------------------------------------------------------------------------
SFML Asset Manager
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
--------------------------------------------------------------------------------

DEPENDENCIES
--------------------------------------------------------------------------------
-- SFML (written using version 2.2, current as of release)
	-- Asset loading function
-- BOOST (version 1.5.7, current as of release)
	-- Serialization
--------------------------------------------------------------------------------

INSTALLATION
--------------------------------------------------------------------------------
Unzip to any directory and include the "include" directory in your IDE.
In your program, use "#include <sf_asset_manager/manager.h>". Do not include the manager.inl file.
* This is a header only library. No linkage is necessary for use.
--------------------------------------------------------------------------------

UNINSTALLATION
--------------------------------------------------------------------------------
Remove the directory. That's all, folks...
--------------------------------------------------------------------------------

USAGE
--------------------------------------------------------------------------------
"Manager.h" contains a template class called "sf::asset::manager<typename KEY, typename T>".
Create an object of sf::asset::manager using the template parameters you want. It's form is very similar to a map,
where the first parameter is the 'key' used to find things, and 'T' is the actual resource.

Class usage and function documentation can be found on my website at: http://www.thatnaughtypanda.com/*
--------------------------------------------------------------------------------

Thank you for using my library!
Please send in questions/concerns/bugs (emphasis on bugs!) to:
jack@thatnaughtypanda.com