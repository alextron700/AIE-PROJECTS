#pragma once
#include <cmath>
namespace MathLibrary
{
    struct Vector3
    {
        // Implement the fields and members as per the assessment...
        float x;
        float y;
        float z;
        Vector3()
        {
            x = 0;
            y = 0;
            z = 0;
        }
        Vector3(const Vector3& input)
        {
            x = input.x;
            y = input.y;
            z = input.z;
        }
        Vector3(float nx, float ny, float nz)
        {
            x = nx;
            y = ny;
            z = nz;
        }
        Vector3 operator+(const Vector3& other)
        {
            return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
        }
        Vector3 operator-(const Vector3& other) const
        {
            return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
        }
        Vector3 operator*(const Vector3& other) 
        {
            return Vector3(this->x * other.x, this->y * other.y, this->z * other.z);
        }
        Vector3 operator*(const float other)
        {
            return Vector3(this->x * other, this->y * other, this->z * other);
        }
        Vector3 operator/(const float other)
        {
            return Vector3(this->x / other, this->y / other, this->z / other);
        }
        Vector3& operator=(const Vector3& other)
        {
            this->x = other.x;
            this->y = other.y;
            this->z = other.z;
            return *this;

        }
        //mathAssigns
        Vector3& operator+=(const Vector3& other)
        {
            this->x += other.x;
            this->y += other.y;
            this->z += other.z;
            return *this;
        }
        Vector3& operator-=(const Vector3& other)
        {
            this->x -= other.x;
            this->y -= other.y;
            this->z -= other.z;
            return *this;
        }
        Vector3& operator*=(const Vector3& other)
        {
            this->x *= other.x;
            this->y *= other.y;
            this->z *= other.z;
            return *this;
        }
        Vector3& operator*=(const float other)
        {
            this->x *= other;
            this->y *= other;
            this->z *= other;
            return *this;
        }
        Vector3& operator/=(const float other)
        {
            this->x /= other;
            this->y /= other;
            this->z /= other;
            return *this;
        }
        Vector3 operator-()
        {
            return Vector3(-x, -y, -z);
        }
        bool operator==(const Vector3& other) const
        {
            return this->x == other.x && this->y == other.y && this->z == other.z;
        }
        bool operator!=(const Vector3& other) const
        {
            return !(this->x == other.x && this->y == other.y && this->z == other.z);
        }
        bool operator<(const Vector3& other)
        {
            double PythagThis = (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
            double PythagOther = (other.x * other.x) + (other.y * other.y) + (other.z * other.z);
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
            };
            throw std::out_of_range("Indexed Out of Bounds!");
        }
        float Dot(const Vector3& B) const
        {
            return (this->x * B.x) + (this->y * B.y) + (this->z * B.z);
        }
        float Magnitude()
        {
            return std::sqrtf((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
        }
        Vector3 Cross(Vector3& B)
        {
            return Vector3((this->y * B.z) - (this->z * B.y), (this->z * B.x) - (this->x * B.z), (this->x * B.y) - (this->y * B.x));
        }
        void Normalise()
        {
            float mag = this->Magnitude();
                if(mag == 0)
                {
                    return;
                }
                this->x /= mag; this->y /= mag; this->z /= mag;
        }
        Vector3 Normalised()
        {
            float mag = this->Magnitude();
            if (mag == 0)
            {
                return Vector3(0, 0, 0);
            }
            return Vector3(x / mag, y / mag, z / mag);
        }
        //checks if two vectors are within an acceptable range
        bool IsApproximatelyEqual(const Vector3& B, float E = 0.0001) const
        {
            return (abs(this->x - B.x) < E) && (abs(this->y - B.y) < E) && (abs(this->z - B.z) < E);
        }
        float AngleBetween(Vector3& B)
        {
            float Amag = this->Magnitude();
            float Bmag = B.Magnitude();
            float ADotB = this->Dot(B);
            float theta = std::acosf(ADotB / (Amag * Bmag));
            return theta;
        }
        float Distance(Vector3& B)
        {
            Vector3 d = *this - B;
            return sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
        }
        float Angle2D()
        {
            return atan2(this->x, this->y);
        }
    };
}