#pragma once

namespace MathLibrary
{
    struct Vector4
    {
        // Implement the fields and members as per the assessment...
        float x;
        float y;
        float z;
        float w;
        Vector4()
        {
            x = 0;
            y = 0;
            z = 0;
            w = 0;
        }
        Vector4(const Vector4& input)
        {
            x = input.x;
            y = input.y;
            z = input.z;
            w = input.w;
        }
        Vector4(float nx, float ny, float nz,float nw)
        {
            x = nx;
            y = ny;
            z = nz;
            w = nw;
        }
        Vector4 operator+(const Vector4& other) const
        {
            return Vector4(this->x + other.x, this->y + other.y, this->z + other.z, other.w);
        }
        Vector4 operator-(const Vector4& other) const
        {
            return Vector4(this->x - other.x, this->y - other.y, this->z - other.z, this->w);
        }
        Vector4 operator*(const Vector4& other) const
        {
            return Vector4(this->x * other.x, this->y * other.y, this->z * other.z, this->w);
        }
        Vector4 operator*(const float other) const
        {
            return Vector4(this->x * other, this->y * other, this->z * other, this->w);
        }
        Vector4 operator/(const float other) const
        {
            return Vector4(this->x / other, this->y / other, this->z / other, this->w);
        }
        Vector4& operator=(const Vector4& other)
        {
            this->x = other.x;
            this->y = other.y;
            this->z = other.z;
            this->w = other.w;
            return *this;

        }
        //mathAssigns
        Vector4& operator+=(const Vector4& other)
        {
            this->x += other.x;
            this->y += other.y;
            this->z += other.z;
            this->w = other.w;
            return *this;
        }
        Vector4& operator-=(const Vector4& other)
        {
            this->x -= other.x;
            this->y -= other.y;
            this->z -= other.z;
            this->w;
            return *this;
        }
        Vector4& operator*=(const Vector4& other)
        {
            this->x *= other.x;
            this->y *= other.y;
            this->z *= other.z;
            this->w *= other.w;
            return *this;
        }
        Vector4& operator*=(const float other)
        {
            this->x *= other;
            this->y *= other;
            this->z *= other;
            this->w;
            return *this;
        }
        Vector4& operator/=(const float other)
        {
            this->x /= other;
            this->y /= other;
            this->z /= other;
            this->w;
            return *this;
        }
        Vector4 operator-() const
        {
            return Vector4(-x, -y, -z, w);
        }
        bool operator==(const Vector4& other) const
        {
            return this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w;
        }
        bool operator!=(const Vector4& other) const
        {
            return !(this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w);
        }
        bool operator<(const Vector4& other) const
        {
            double PythagThis = (this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w *this->w);
            double PythagOther = (other.x * other.x) + (other.y * other.y) + (other.z * other.z) + (other.w * other.w);
            return PythagThis < PythagOther;
        }
        float operator[](int index) const
        {
            switch (index)
            {
            case 0:
                return this->x;
                break;
            case 1:
                return this->y;
                break;
            case 2:
                return this->z;
                break;
            case 3:
                return this->w;
            };
            throw std::out_of_range("Indexed Out of Bounds!");
        }
        float& operator[](int index) 
        {
            switch (index)
            {
            case 0:
                return this->x;
                break;
            case 1:
                return this->y;
                break;
            case 2:
                return this->z;
                break;
            case 3:
                return this->w;
            };
            throw std::out_of_range("Indexed Out of Bounds!");
        }
        float Dot(const Vector4& B) const
        {
            return (this->x * B.x) + (this->y * B.y) + (this->z * B.z);
        }
        float Magnitude() const
        {
            return std::sqrtf((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
        }
        Vector4 Cross(const Vector4& B) const
        {
            return Vector4((this->y * B.z) - (this->z * B.y), (this->z * B.x) - (this->x * B.z), (this->x * B.y) - (this->y * B.x), 0.0f);
        }
        void Normalise()
        {
            float mag = this->Magnitude();
            if (mag == 0)
            {
                return;
            }
            this->x /= mag; this->y /= mag; this->z /= mag;
        }
        Vector4 Normalised() const
        {
            Vector4 temp = *this;
            temp.Normalise();
            return temp;
        }
        //checks if two vectors are within an acceptable range
        bool IsApproximatelyEqual(const Vector4& B, float E = 0.0001) const
        {
            return (abs(this->x - B.x) < E) && (abs(this->y - B.y) < E) && (abs(this->z - B.z) < E) && (abs(this->w - B.w)< E);
        }
        float AngleBetween(const Vector4& B) const
        {
            float Amag = this->Magnitude();
            float Bmag = B.Magnitude();
            float ADotB = this->Dot(B);
            float theta = std::acosf(ADotB / (Amag * Bmag));
            return theta;
        }
        float Distance(const Vector4& B) const 
        {
            Vector4 D = *this - B;
            return sqrtf((D.x * D.x) + (D.y * D.y) + (D.z * D.z) + (D.w * D.w));
        }
    };
}