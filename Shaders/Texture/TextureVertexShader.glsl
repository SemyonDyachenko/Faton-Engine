#version 330 core

		layout(location = 0) in vec3 position;
		layout(location = 1) in vec2 aTexCoord;

		uniform mat4 ViewProjectionMatrix;
		uniform mat4 Transform;

		out vec2 TexCoord;



		void main()
		{
			
			gl_Position = ViewProjectionMatrix  * Transform * vec4(position,1.0);
			TexCoord = aTexCoord;
		
		}	
