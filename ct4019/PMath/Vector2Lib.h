#pragma once
#include <vector>

	class Vector2
	{
	public:
		// Constructors
		Vector2()
		{
			m_fX = 0.0f;
			m_fY = 0.0f;
		}
		Vector2(float a_x, float a_y)
		{
			m_fX = a_x;
			m_fY = a_y;
		}

		float GetMagnitude() const;
		void NormaliseSelf();
		Vector2 Normalise();

		//destructor
		~Vector2() {}

		//overloads
		bool operator==(const Vector2& a_vParam);
		Vector2 operator*(const Vector2& a_vParam);
		Vector2& operator=(const float a_avParam[2]);
		Vector2 operator*(const float a_fParam) const;
		Vector2 operator+(const Vector2& a_vParam);
		Vector2 operator-(const Vector2& a_vParam);

		// Getters
		float GetX() const { return m_fX; }
		float GetY() const { return m_fY; }

		// Setters
		void SetX(float a_fX) { m_fX = a_fX; }
		void SetY(float a_fY) { m_fY = a_fY; }

		static Vector2 RandomVector();

	private:
		float m_fX;
		float m_fY;
		bool m_bIsNormalised;
	};

	class DjikstraNode : public Vector2 {

	public:
		DjikstraNode() : Vector2() {
		};

		DjikstraNode(float a_x, float a_y) : Vector2()
		{
		};

		std::vector<DjikstraNode*> vConnectedNodes;
	};