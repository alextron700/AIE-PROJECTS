#pragma once

namespace MathLibrary
{
    struct Matrix4
    {
        // Implement the fields and members as per the assessment...


            // Implement the fields and members as per the assessment...
        float m1, m2, m3, m4;
        float m5, m6, m7, m8;
        float m9, m10, m11, m12;
        float m13, m14, m15, m16;
        Matrix4()
        {
            m1 = 1;
            m6 = 1;
            m11 = 1;
            m16 = 1;
            m2= m3= m4= m7= m8= m5= m9= m10= m13= m12= m14= m15 = 0;
        }
        Matrix4(const Matrix4& other)
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
            m10 = other.m10;
            m11 = other.m11;
            m12 = other.m12;
            m13 = other.m13;
            m14 = other.m14;
            m15 = other.m15;
            m16 = other.m16;
        }
        Matrix4(
            float M1, float M2, float M3, float M4, 
            float M5, float M6, float M7, float M8, 
            float M9, float M10, float M11, float M12, 
            float M13, float M14, float M15, float M16)
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
            m10 = M10;
            m11 = M11;
            m12 = M12;
            m13 = M13;
            m14 = M14;
            m15 = M15;
            m16 = M16;
        }
        Matrix4& operator=(const Matrix4& other)
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
            this->m10 = other.m10;
            this->m11 = other.m11;
            this->m12 = other.m12;
            this->m13 = other.m13;
            this->m14 = other.m14;
            this->m15 = other.m15;
            this->m16 = other.m16;
            return *this;
        }
        Vector4 operator*(const Vector4& other) const
        {
            Vector4 R0 = Vector4(this->m1, this->m5, this->m9, this->m13);
            Vector4 R1 = Vector4(this->m2, this->m6, this->m10, this->m14);
            Vector4 R2 = Vector4(this->m3, this->m7, this->m11, this->m15);
            Vector4 R3 = Vector4(this->m4, this->m8, this->m12, this->m16);
            auto Dot = [](Vector4 A, Vector4 B)
                {
                    return (A.x * B.x) + (A.y * B.y) + (A.z * B.z) + (A.w * B.w);
                };
            return Vector4(Dot(R0,other),Dot(R1,other),Dot(R2,other),Dot(R3,other));
        }
        Matrix4 operator*(const Matrix4& other)
        {
            /*R
           C 0 1 2 3
           0 0 1 2 3
           1 4 5 6 7
           2 8 9 A B
           3 C D E F
            */
            Vector4 R0 = Vector4(this->m1, this->m5, this->m9, this->m13);
            Vector4 R1 = Vector4(this->m2, this->m6, this->m10, this->m14);
            Vector4 R2 = Vector4(this->m3, this->m7, this->m11, this->m15);
            Vector4 R3 = Vector4(this->m4, this->m8, this->m12, this->m16);
            Vector4 C0 = Vector4(other.m1, other.m2, other.m3, other.m4);
            Vector4 C1 = Vector4(other.m5, other.m6, other.m7, other.m8);
            Vector4 C2 = Vector4(other.m9, other.m10, other.m11, other.m12);
            Vector4 C3 = Vector4(other.m13, other.m14, other.m15, other.m16);
            auto Dot = [](Vector4 A, Vector4 B)
                {
                    return (A.x * B.x) + (A.y*B.y) + (A.z * B.z) + (A.w * B.w);
                };
            Matrix4 X;
            X.m1 = Dot(R0,C0);
            X.m2 = Dot(R1,C0);
            X.m3 = Dot(R2,C0);
            X.m4 = Dot(R3,C0);
            X.m5 = Dot(R0,C1);
            X.m6 = Dot(R1,C1);
            X.m7 = Dot(R2,C1);
            X.m8 = Dot(R3,C1);
            X.m9 = Dot(R0,C2);
            X.m10 = Dot(R1,C2);
            X.m11 = Dot(R2,C2);
            X.m12 = Dot(R3,C2);
            X.m13 = Dot(R0,C3);
            X.m14 = Dot(R1,C3);
            X.m15 = Dot(R2,C3);
            X.m16 = Dot(R3,C3);
            return X;
        }
        Matrix4& operator*=(const Matrix4& other)
        {
            *this = *this * other;
            return *this;
        }

        static Matrix4 MakeRotateX(float theta)
        {
            /*R
         C 0 1 2 3
         0 0 1 2 3
         1 4 5 6 7
         2 8 9 A B
         3 C D E F
          */
            Matrix4 R;
            R.m6 = cos(theta);
            R.m7 = -sin(theta);
            R.m10 = sin(theta);
            R.m11 = cos(theta);
            return R;
        }
        static Matrix4 MakeRotateY(float theta)
        {
            Matrix4 R;
            R.m1 = cos(theta);
            R.m3 = sin(theta);
            R.m9 = -sin(theta);
            R.m11 = cos(theta);
            return R;
        }
        static Matrix4 MakeRotateZ(float theta)
        {
            Matrix4 R;
            R.m1 = cos(theta);
            R.m2 = sin(theta);
            R.m6 = cos(theta);
            R.m5 = -sin(theta);
            return R;
        }
        static Matrix4 MakeScale(Vector4& input)
        {
            Matrix4 S;
            S.m1 = input.x;
            S.m6 = input.y;
            S.m11 = input.z;
            S.m16 = input.w;
            return S;
        }
        static Matrix4 MakeScale(float x, float y, float z) 
        {
            Vector4 X = Vector4(x, y, z, 1.0f);
            return MakeScale(X);
        }
        static Matrix4 MakeTranslation(Vector4& input)
        {
            Matrix4 T;
            T.m13 = input.x;
            T.m14 = input.y;
            T.m15 = input.z;
            T.m16 = input.w;
            return T;
        }
        static Matrix4 MakeTranslation(float x, float y, float z)
        {
            Vector4 X = Vector4(x, y, z, 1);
            return MakeTranslation(X);
        }
       
        Vector4 GetRight() const
        {
            return Vector4(m1, m2, m3, m4);
        }
        Vector4 GetUp() const 
        {
            return Vector4(m5, m6, m7, m8);
        }
        Vector4 GetForward() const 
        {
            return Vector4(m9, m10, m11, m12);
        }
        Vector4 GetPosition() const
        {
            return Vector4(m13, m14, m15, m16);
        }
        bool IsApproximatelyEqual(const Matrix4& other, float E = 1e-4) const
        {
           // double sigmaThis = static_cast<double>(m1) + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + m10 + m11 + m12 + m13 + m14 + m15 + m16;
           // double sigmaOther = other.m1 + other.m2 + other.m3 + other.m4 + other.m5 + other.m6 + other.m7 + other.m8 + other.m9 + other.m10 + other.m11 + other.m12 + other.m13 + other.m14 + other.m15 + other.m16;
           // return abs(sigmaThis - sigmaOther) <= (E * 16); // evil hack. 
            float Sthis[16] = {m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11,m12,m13,m14,m15,m16};
            float Sother[16] = { other.m1, other.m2 , other.m3 , other.m4 , other.m5 , other.m6 , other.m7 , other.m8 , other.m9 , other.m10 , other.m11 , other.m12 , other.m13 , other.m14 , other.m15 , other.m16 };
            for (int i = 0; i < 16; i++)
            {
                if (fabsf(Sthis[i] - Sother[i]) > E)
                {
                    return false;
                }
                if (std::isnan(Sthis[i]) || std::isnan(Sother[i]))
                {
                    return false;
                }
            }
            return true;
        }
        bool operator==(const Matrix4& other) const
        {
            return this->IsApproximatelyEqual(other, 0.0f);
        }
        void setTranslate(Vector4& pos)
        {
            this->m4 = pos.x;
            this->m8 = pos.y;
            this->m12 = pos.z;
            this->m16 = pos.w;
        }
        float operator[](int input) const
        {
            switch (input % 15)
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
            case 9:
                return m10;
            case 10:
                return m11;
            case 11:
                return m12;
            case 12:
                return m13;
            case 13:
                return m14;
            case 14:
                return m15;
            case 15:
                return m16;
            }
            throw std::out_of_range("Indexed Out of Bounds!");
        }
        float& operator[](int input)
        {
            switch (input % 16)
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
            case 9:
                return m10;
            case 10:
                return m11;
            case 11:
                return m12;
            case 12:
                return m13;
            case 13:
                return m14;
            case 14:
                return m15;
            case 15:
                return m16;
            }
            throw std::out_of_range("Indexed Out of Bounds!");
        }
    };
}