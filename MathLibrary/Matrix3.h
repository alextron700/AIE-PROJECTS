#pragma once
#include <Vector3.h>
namespace MathLibrary
{

    struct Matrix3
    {
        // Implement the fields and members as per the assessment...
        float m1, m2, m3;
        float m4, m5, m6;
        float m7, m8, m9;
        Matrix3()
        {
            m1 = 1; m2 = 0; m3 = 0;
            m4 = 0; m5 = 1; m6 = 0;
            m7 = 0; m8 = 0; m9 = 1;
            
        }
        Matrix3(const Matrix3& other)
        {
            m1 = other.m1;
            m2 = other.m2;
            m3 = other.m3;
            m4 = other.m4;
            m5 = other.m5;
            m6 = other.m6;
            m7 = other.m7;
            m8 = other.m8;
            m9 = other.m9;
        }
        Matrix3(
            float M1, float M2, float M3, 
            float M4, float M5, float M6, 
            float M7, float M8, float M9
        )
        {
            m1 = M1;
            m2 = M2;
            m3 = M3;
            m4 = M4;
            m5 = M5;
            m6 = M6;
            m7 = M7;
            m8 = M8;
            m9 = M9;
        }
        Matrix3& operator=(const Matrix3& other)
        {
            this->m1 = other.m1;
            this->m2 = other.m2;
            this->m3 = other.m3;
            this->m4 = other.m4;
            this->m5 = other.m5;
            this->m6 = other.m6;
            this->m7 = other.m7;
            this->m8 = other.m8;
            this->m9 = other.m9;
            return *this;
        }
        
        Vector3 operator*(const Vector3& other) const
        {
            Vector3 R0 = Vector3(this->m1, this->m4, this->m7);
            Vector3 R1 = Vector3(this->m2, this->m5, this->m8);
            Vector3 R2 = Vector3(this->m3, this->m6, this->m9);
           return Vector3(R0.Dot(other), R1.Dot(other), R2.Dot(other));
        }
        Matrix3 operator*(const Matrix3& other) const
        {
            Vector3 R0 = Vector3(this->m1, this->m2, this->m3);
            Vector3 R1 = Vector3(this->m4, this->m5, this->m6);
            Vector3 R2 = Vector3(this->m7, this->m8, this->m9);
            Vector3 C0 = Vector3(other.m1, other.m4, other.m7);
            Vector3 C1 = Vector3(other.m2, other.m5, other.m8);
            Vector3 C2 = Vector3(other.m3, other.m6, other.m9);
            Matrix3 X;
            X.m1 = R0.Dot(C0);
            X.m2 = R0.Dot(C1);
            X.m3 = R0.Dot(C2);
            X.m4 = R1.Dot(C0);
            X.m5 = R1.Dot(C1);
            X.m6 = R1.Dot(C2);
            X.m7 = R2.Dot(C0);
            X.m8 = R2.Dot(C1);
            X.m9 = R2.Dot(C2);
            return X;
        }
        Matrix3& operator*=(const Matrix3& other)
        {
            *this = *this * other;
            return *this;
        }
       
        static Matrix3 MakeRotate(float theta)
        {
            Matrix3 R;
            R.m1 = cos(theta);
            R.m2 = sin(theta);
            R.m4 = -sin(theta);
            R.m5 = cos(theta);
            return R;
        }
        static Matrix3 MakeScale(const Vector3& input)  
        {
            Matrix3 S;
            S.m1 = input.x;
            S.m5 = input.y;
            return S;
        }
        static Matrix3 MakeScale(float x, float y)
        {
            Vector3 X = Vector3(x, y, 0);
            return MakeScale(X);
        }
        static Matrix3 MakeTranslation(const Vector3& input)
        {
            Matrix3 T;
            T.m3 = input.x;
            T.m6 = input.y;
            return T;
        }
        Vector3 GetRight() const 
        {
            return Vector3(m4,m5,m6);
        }
        Vector3 GetForward() const
        {
            return Vector3(m1, m2, m3);
        }
        Vector3 GetTranslate() const 
        {
            return Vector3(m7, m8, m9);
        }
        bool IsApproximatelyEqual(const Matrix3& other, float E = 0.0001) const
        {
            double sigmaThis = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9;
            double sigmaOther = other.m1 + other.m2 + other.m3 + other.m4 + other.m5 + other.m6 + other.m7 + other.m8 + other.m9;
            return abs(sigmaThis - sigmaOther) <= E;
        }
        bool operator==(const Matrix3& other) const
        {
            return this->IsApproximatelyEqual(other, 0.0f);
        }
        float operator[] (int index) const
        {
            switch (index)
            {
            case 0:
                return m1;
            case 1:
                return m2;
            case 2:
                return m3;
            case 3:
                return m4;
            case 4:
                return m5;
            case 5:
                return m6;
            case 6:
                return m7;
            case 7:
                return m8;
            case 8:
                return m9;
            }
            throw std::out_of_range("Indexed Out of Bounds!");
        }
        float& operator[] (int index)
        {
            switch (index)
            {
            case 0:
                return m1;
            case 1:
                return m2;
            case 2:
                return m3;
            case 3:
                return m4;
            case 4:
                return m5;
            case 5:
                return m6;
            case 6:
                return m7;
            case 7:
                return m8;
            case 8:
                return m9;
            }
            throw std::out_of_range("Indexed Out of Bounds!");
        }
    };
}