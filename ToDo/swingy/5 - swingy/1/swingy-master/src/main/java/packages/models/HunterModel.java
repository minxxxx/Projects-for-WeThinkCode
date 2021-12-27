package packages.models;

import packages.interfaces.IHero;
import packages.enums.ArmorType;
import packages.enums.CharacterType;
import packages.enums.HelmType;
import packages.enums.WeaponType;

public class HunterModel extends HeroModel implements IHero
{
    public HunterModel(String name, CharacterType type, int level, int xPoints, int attack, int defense, int hitPoints, WeaponType weapon, ArmorType armor, HelmType helm, String icon)
    {
        super(name, type, level, xPoints, attack, defense, hitPoints, weapon, armor, helm,  icon);
    }
}