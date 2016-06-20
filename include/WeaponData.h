#ifndef WEAPONDATA_H
#define WEAPONDATA_H


class WeaponData
{
    public:
        WeaponData(int identifier);
        virtual ~WeaponData();

        //void setData(int identifier);

        int clipSize;
        int bullets;

        int bulletspeed;
        int shootingspeed;


    protected:

    private:
};

#endif // WEAPONDATA_H
