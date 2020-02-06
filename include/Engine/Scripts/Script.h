#ifndef ENGINE_SCRIPT_H
#define ENGINE_SCRIPT_H
#include <string>


extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

#ifndef _WIN32
#pragma comment(lib,"liblua53.a")
#endif


namespace Engine
{
	/*class Script
	{
	private:
		lua_State *m_Lua_State;
	public:
		Script();

		virtual ~Script();

		void Create();

		void Close();

		int ScriptFromFile(const char* path);

		template<class T>
		void RegisterConstant(T value,const char * name);

		void Array();

		template<class T>
		void RegisterConstantArray(T value, int index);

		void RegisterArray(char* arrayname);

		int GetArgumentCount();

		template<class T>
		T GetArgument(int index);

		template<class T>
		void Return(T value);
	};
*/
}


#endif