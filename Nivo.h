class Niveau{

    private :
        int nbEnnemis;
        int HSol;
        sf::Sprite sprite;

    public :
        Niveau(sf::Texture textureNiveau,int nbEnnemis, int scale, int HSol);
        void load();


};

    //Declaration du sprite du Niveau
    /*    Sprite spriteNiv;

        //Assignation de la texture
        spriteNiv.setTexture(textureNiv);
        //Ajustement Taille et positionnement
        spriteNiv.setScale(Vector2f(5.0f,5.0f));
        spriteNiv.setPosition(Vector2f(0,-2100));
*/
