CREATE TABLE `rayon`(`numeroRayon` INTEGER,`nomRayon` VARCHAR(25),primary key(`numeroRayon`));

CREATE TABLE `variete`(`numeroVariete` INTEGER,`nomVariete` VARCHAR(25),`numeroRayon` INTEGER NOT NULL, foreign key (`numeroRayon`) references rayon(`numeroRayon`),primary key(`numeroVariete`));

CREATE TABLE `client`(`numeroClient` INTEGER,`nomClient` INTEGER,`prenomClient` INTEGER,`mailClient` VARCHAR(50),`mdpClient` VARCHAR(100),primary key(`numeroClient`));

CREATE TABLE `unite`(`numeroUnite` INTEGER,`libelleUnite` VARCHAR(25),primary key(`numeroUnite`));

CREATE TABLE `typeAbonnement`(`numeroTypeAbonnement` INTEGER,`libelleTypeAbonnement` VARCHAR(25),`prixTypeAbonnement` FLOAT,`dureeTypeAbonnement` INTEGER,primary key(`numeroTypeAbonnement`));

CREATE TABLE `ticket`(`numeroTicket` INTEGER,`contenuTicket` VARCHAR(100),`numeroClient` INTEGER NOT NULL, foreign key (`numeroClient`) references client(`numeroClient`),primary key(`numeroTicket`));

CREATE TABLE `TypeUtilisateur`(`numeroTypeUtilisateur` INTEGER,`libelleTypeUtilisateur` VARCHAR(25),primary key(`numeroTypeUtilisateur`));

CREATE TABLE `abonnement`(`numeroAbonnement` INTEGER,`dateDebutAbonnement` DATE,`dateFinAbonnement` DATE,`numeroTypeAbonnement` INTEGER NOT NULL, foreign key (`numeroTypeAbonnement`) references typeAbonnement(`numeroTypeAbonnement`),primary key(`numeroAbonnement`));

CREATE TABLE `producteur`(`numeroProducteur` INTEGER,`loginProducteur` VARCHAR(25),`nomProducteur` VARCHAR(25),`prenomProducteur` VARCHAR(25),`adresseProducteur` VARCHAR(150),`telProducteur` VARCHAR(25),`mdpProducteur` VARCHAR(100),`dateInscriptionProducteur` DATE,`numeroAbonnement` INTEGER NOT NULL,`numeroTicket` INTEGER NOT NULL, foreign key (`numeroAbonnement`) references abonnement(`numeroAbonnement`), foreign key (`numeroTicket`) references ticket(`numeroTicket`),primary key(`numeroProducteur`));

CREATE TABLE `produit`(`numeroProduit` INTEGER,`nomProduit` VARCHAR(25),`informationProduit` VARCHAR(100),`imageProduit` VARCHAR(25),`quantiteProduit` FLOAT,`numeroVariete` INTEGER NOT NULL, foreign key (`numeroVariete`) references variete(`numeroVariete`),primary key(`numeroProduit`));

CREATE TABLE `semaine`(`dateDebutSemaine` DATE,`dateFinSemaine` DATE,`numeroTicket` INTEGER NOT NULL, foreign key (`numeroTicket`) references ticket(`numeroTicket`),primary key(`dateDebutSemaine`));

CREATE TABLE `Utilisateur`(`numeroUtilisateur` INTEGER,`prenomUtilisateur` VARCHAR(25),`nomUtilisateur` VARCHAR(25),`adresseUtilisateur` VARCHAR(150),`loginUtilisateur` VARCHAR(50),`mdpUtilisateur` VARCHAR(200),`mailUtilisateur` VARCHAR(50),`telUtilisateur` VARCHAR(25),`numeroTypeUtilisateur` INTEGER NOT NULL, foreign key (`numeroTypeUtilisateur`) references TypeUtilisateur(`numeroTypeUtilisateur`),primary key(`numeroUtilisateur`));

CREATE TABLE `rejet`(`numeroRejet` INTEGER,`raisonRejet` VARCHAR(200),`numeroUtilisateur` INTEGER NOT NULL,`numeroProducteur` INTEGER NOT NULL, foreign key (`numeroUtilisateur`) references Utilisateur(`numeroUtilisateur`), foreign key (`numeroProducteur`) references producteur(`numeroProducteur`),primary key(`numeroRejet`));

CREATE TABLE `commande`(`numeroCommande` INTEGER,`dateRecuperationCommande` DATE,`datePassageCommande` DATE,`commandeRecuperee` BOOL,`prixTotalCommande` FLOAT,`numeroClient` INTEGER NOT NULL,`numeroProducteur` INTEGER NOT NULL, foreign key (`numeroClient`) references client(`numeroClient`), foreign key (`numeroProducteur`) references producteur(`numeroProducteur`),primary key(`numeroCommande`));

CREATE TABLE `Produire`(`quantite` INTEGER,`prixUnitaire` FLOAT,`numeroProducteur` INTEGER NOT NULL,`numeroProduit` INTEGER NOT NULL,`dateDebutSemaine` DATE NOT NULL,`numeroUnite` INTEGER NOT NULL, foreign key (`numeroProducteur`) references producteur(`numeroProducteur`), foreign key (`numeroProduit`) references produit(`numeroProduit`), foreign key (`dateDebutSemaine`) references semaine(`dateDebutSemaine`), foreign key (`numeroUnite`) references unite(`numeroUnite`),primary key(`numeroProducteur`,`numeroProduit`,`dateDebutSemaine`));

CREATE TABLE `LDC`(`quantite` FLOAT,`numeroProducteur` INTEGER NOT NULL,`numeroProduit` INTEGER NOT NULL,`dateDebutSemaine` DATE NOT NULL,`numeroCommande` INTEGER NOT NULL, foreign key (`numeroProducteur`,`numeroProduit`,`dateDebutSemaine`) references Produire(`numeroProducteur`,`numeroProduit`,`dateDebutSemaine`), foreign key (`numeroCommande`) references commande(`numeroCommande`),primary key(`numeroProducteur`,`numeroProduit`,`dateDebutSemaine`,`numeroCommande`));













