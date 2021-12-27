package packages.models;

import packages.enums.ArmorType;
import packages.enums.HelmType;
import packages.enums.CharacterType;
import packages.enums.WeaponType;
import packages.interfaces.IHero;


public class ElfModel extends HeroModel implements IHero
{
    public ElfModel(String name, CharacterType type, int level, int xPoints, int attack, int defense, int hitPoints, WeaponType weapon, ArmorType armor, HelmType helm, String icon)
    {
        super(name, type, level, xPoints, attack, defense, hitPoints, weapon, armor, helm, icon);
    }
}