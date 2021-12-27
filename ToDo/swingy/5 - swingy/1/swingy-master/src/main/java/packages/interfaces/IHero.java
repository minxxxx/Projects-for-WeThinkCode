package packages.interfaces;

import packages.console.controller.Coordinates;
import packages.enums.ArmorType;
import packages.enums.HelmType;
import packages.enums.CharacterType;
import packages.enums.WeaponType;

public interface IHero
{
    public int getId();

    public void setName(String name);
    
    public void setType(CharacterType characterType);

    public void setLevel(int level);

    public void setXPoints(int xPoints);

    public void setAttack(int attack);

    public void setDefense(int defense);
    
    public void setHitPoints(int hitPoints);    

    public void setWeapon(WeaponType weaponType);
    
    public void setArmor(ArmorType armorType);

    public void setHelm(HelmType helmType);

    public void setCoordinates(Coordinates coordinates);
    
    public String getName();
    
    public CharacterType getType();

    public int getLevel();

    public int getXPoints();

    public int getAttack();

    public int getDefense();
    
    public int getHitPoints();    

    public WeaponType getWeapon();
    
    public ArmorType getArmor();

    public HelmType getHelm();

    public Coordinates getCoordinates();

}