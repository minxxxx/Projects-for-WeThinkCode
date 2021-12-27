package packages.utils;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import packages.console.controller.Coordinates;
import packages.enums.ArmorType;
import packages.enums.CharacterType;
import packages.enums.HelmType;
import packages.enums.WeaponType;
import packages.models.EnemyModel;
import packages.models.HeroModel;

public class EnemyFactory{
    public static String[] enemyName = {"Terminus", "Inara", "Strix", "Jenos", "Makoa", "Sha Lin", "Drogoz", "Bomb King", "Evie", "Androxus"};

    public static List<EnemyModel> getEnemyList(HeroModel hero){
        List<EnemyModel> enemyList = new ArrayList<EnemyModel>();
        Random random = new Random();
        int mapSize = Formulas.sizeMap(hero.getLevel());
        int level = hero.getLevel();
        int numberOfEnemies = Formulas.getNumberOfEnemiesToSpawn(hero);

        for(int i = 0; i <= numberOfEnemies; i++){
            EnemyModel enemy = new EnemyModel(enemyName[random.nextInt(6)], CharacterType.enemy, level, 0,
            10 + random.nextInt(hero.getAttack()),
            5 + random.nextInt(hero.getDefense()),
            20 + random.nextInt(hero.getHitPoints() - 10),
            WeaponType.values()[random.nextInt(WeaponType.values().length)], 
            ArmorType.values()[random.nextInt(ArmorType.values().length)], 
            HelmType.values()[random.nextInt(HelmType.values().length)],
            "src/main/java/packages/images/villan-med.png");
            
            enemy.setCoordinates(new Coordinates(random.nextInt(mapSize), random.nextInt(mapSize)));
            if (isSamePosition(enemyList, enemy) || enemy.getCoordinates().Isequals(hero.getCoordinates())){
                i--;
                continue ;
            }
            enemyList.add(enemy);
        }
        return (enemyList);
    }

    private static Boolean isSamePosition(List<EnemyModel> enemyList, EnemyModel enemy){
        for (EnemyModel e : enemyList) {
            if (enemy.getCoordinates().Isequals(e.getCoordinates())){
                return (true);
            }
        }
        return (false);
    }
}