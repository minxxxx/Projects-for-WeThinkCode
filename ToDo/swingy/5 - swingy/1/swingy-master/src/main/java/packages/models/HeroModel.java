package packages.models;

import packages.console.controller.Coordinates;
import packages.enums.ArmorType;
import packages.enums.CharacterType;
import packages.enums.WeaponType;
import packages.enums.HelmType;

import javax.validation.constraints.*;

public class HeroModel
{
	private static int _idCounter = 0;

	@NotNull
	protected int _id = 0;

	@NotNull
	@NotEmpty
	protected String _name;

	@NotNull
    protected CharacterType _type;

	@PositiveOrZero
    protected int _level;

    @PositiveOrZero
    protected int _xPoints;

    @PositiveOrZero
    protected int _attack;

    @PositiveOrZero
    protected int _defense;

    @PositiveOrZero
    protected int _hitPoints;

    @NotNull
    protected WeaponType _weapon;

    @NotNull
	protected ArmorType _armor;

    @NotNull
	protected HelmType _helm;

    @NotNull
	@NotEmpty
	protected String _icon;

    @NotNull
	protected Coordinates _coordinates;	
	
	public HeroModel(String name, CharacterType type, int level, int xPoints, int attack, int defense, int hitPoints, WeaponType weapon, ArmorType armor, HelmType helm, String icon)
	{
		this._icon = icon;
		_id = setNextId();
		this._name = name;
		this._type = type;
		this._level = level;
		this._xPoints = xPoints;
		this._attack = attack;
		this._defense = defense;
		this._hitPoints = hitPoints;
		this._weapon = weapon;
		this._armor = armor;
		this._helm = helm;
		_coordinates = new Coordinates(0, 0);
	}

	public void setCoordinates(Coordinates coordinates)
	{
		this._coordinates = coordinates;
	}

	private int setNextId()
	{
		return (++_idCounter);
	}

	public int getId()
    {
        return _id;
    }

	public void setName(String name) {
		this._name = name;
	}

    public void setType(CharacterType characterType)
    {
        this._type = characterType;
    }

	public void setLevel(int level) {
		this._level = level;
	}

	public void setXPoints(int xPoints) {
		this._xPoints = xPoints;
	}

	public void setAttack(int attack) {
		this._attack = attack;
	}

	public void setDefense(int defense) {
		this._defense = defense;
	}

	public void setHitPoints(int hitPoints) {
		this._hitPoints = hitPoints;
	}

	public void setWeapon(WeaponType weaponType) {
		this._weapon = weaponType;
	}

	public void setArmor(ArmorType armorType) {
		this._armor = armorType;
	}

	public void setHelm(HelmType helmType) {
		this._helm = helmType;
	}

	public void setIcon(String icon) {
		this._icon = icon;
	}

	public String getName() {
		return this._name;
	}

    public CharacterType getType()
    {
        return this._type;
    }

	public int getLevel() {
		return this._level;
	}

	public int getXPoints() {
		return this._xPoints;
	}

	public int getAttack() {
		return this._attack;
	}

	public int getDefense() {
		return this._defense;
	}

	public int getHitPoints() {
		return this._hitPoints;
	}

	public WeaponType getWeapon() {
		return this._weapon;
	}

	public ArmorType getArmor() {
		return this._armor;
	}

	public HelmType getHelm() {
		return this._helm;
	}

	public String getIcon() {
		return this._icon;
	}

	public Coordinates getCoordinates()
	{
		return this._coordinates;
	}
}