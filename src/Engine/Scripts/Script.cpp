#include "../../../include/Engine/Scripts/Script.h"


namespace Engine
{


	/*Script::Script()
	{
		
	}

	Script::~Script()
	{
	}

	void Script::Create()
	{
		m_Lua_State = luaL_newstate();

		static const luaL_Reg lualibs[] =
		{
			{"base",luaopen_base},
			{"io",luaopen_io},
			{NULL,NULL}

		};

		for (const luaL_Reg * lib = lualibs; lib->func != NULL; lib++)
		{
			luaL_requiref(m_Lua_State, lib->name, lib->func, 1);
			lua_settop(m_Lua_State, 0);
		}
	}

	void Script::Close()
	{
		lua_close(m_Lua_State);
	}

	int Script::ScriptFromFile(const char* path)
	{
		luaL_dofile(m_Lua_State, path);

		return lua_tointeger(m_Lua_State, lua_gettop(m_Lua_State));
	}

	void Script::Array()
	{
		lua_createtable(m_Lua_State, 2, 0);
	}


	void Script::RegisterArray(char* arrayname)
	{
		lua_setglobal(m_Lua_State, arrayname);
	}

	int Script::GetArgumentCount()
	{
		return lua_gettop(m_Lua_State);
	}


	template <>
	void Script::RegisterConstant<int>(int value, const char* name)
	{
		lua_pushinteger(m_Lua_State, value);
		lua_setglobal(m_Lua_State, name);
	}

	template<>
	void Script::RegisterConstant<double>(double value,const char* name)
	{
		lua_pushnumber(m_Lua_State, value);
		lua_setglobal(m_Lua_State, name);
	}
	
	template<>
	void Script::RegisterConstant<char>(char value, const char* name)
	{
		lua_pushstring(m_Lua_State, &value);
		lua_setglobal(m_Lua_State, name);
	}

	template<>
	void Script::RegisterConstant<bool>(bool value,const char* name)
	{
		lua_pushboolean(m_Lua_State, value);
		lua_setglobal(m_Lua_State, name);
	}

	template<>
	void Script::RegisterConstant<lua_CFunction>(lua_CFunction value, const  char* name)
	{
		lua_pushcfunction(m_Lua_State, value);
		lua_setglobal(m_Lua_State, name);
	}

	template<>
		void Script::RegisterConstantArray<int>(int value, int index)
	{
		lua_pushnumber(m_Lua_State, index);
		lua_pushinteger(m_Lua_State, value);
		lua_settable(m_Lua_State, -3);
	}

	template<>
		void Script::RegisterConstantArray<double>(double value, int index)
	{
		lua_pushnumber(m_Lua_State, index);
		lua_pushnumber(m_Lua_State, value);
		lua_settable(m_Lua_State, -3);
	}

	template<>
		void Script::RegisterConstantArray<char>(char value, int index)
	{
		lua_pushnumber(m_Lua_State, index);
		lua_pushstring(m_Lua_State, &value);
		lua_settable(m_Lua_State, -3);
	}

	template<>
		void Script::RegisterConstantArray<bool>(bool value, int index)
	{
		lua_pushnumber(m_Lua_State, index);
		lua_pushboolean(m_Lua_State, value);
		lua_settable(m_Lua_State, -3);
	}

	template<>
		void Script::RegisterConstantArray<lua_CFunction>(lua_CFunction value, int index)
	{
		lua_pushnumber(m_Lua_State, index);
		lua_pushcfunction(m_Lua_State, value);
		lua_settable(m_Lua_State, -3);
	}



		template<>
			int Script::GetArgument<int>(int index)
		{
			return lua_tointeger(m_Lua_State, index);
		}

		template<>
			double Script::GetArgument<double>(int index)
		{
			return lua_tonumber(m_Lua_State, index);
		}

		template<>
			char Script::GetArgument<char>(int index)
		{
			return (char)lua_tostring(m_Lua_State, index);
		}

		template<>
			bool Script::GetArgument<bool>(int index)
		{
			return lua_toboolean(m_Lua_State, index);
		}


			template<>
			void Script::Return<int>(int value)
			{
				lua_pushinteger(m_Lua_State, value);
			}

			template<>
			void Script::Return<double>(double value)
			{
				lua_pushnumber(m_Lua_State, value);
			}

			template<>
			void Script::Return<char>(char value)
			{
				lua_pushstring(m_Lua_State, &value);
			}

			template<>
			void Script::Return<bool>(bool value)
			{
				lua_pushboolean(m_Lua_State, value);
			}*/

}
