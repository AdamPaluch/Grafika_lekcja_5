#include <GL\freeglut.h>
#include <iostream>
#include "materials.h"

enum
{
	BRASS,
	BRONZE,
	POLISHED_BRONZE,
	CHROME,
	COPPER,
	POLISHED_COPPER,
	GOLD,
	POLISHED_GOLD,
	PEWTER,
	SILVER,
	POLISHED_SILVER,
	EMERALD,
	JADE,
	OBSIDIAN,
	PEARL,
	RUBY,
	TURQUOISE,
	BLACK_PLASTIC,
	BLACK_RUBBER,
};

int button_x;
int button_y;
int button_state = GLUT_UP;
float rotatex;
float rotatey;

float lightPosition[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

float  ambientLight[4] = { 0.5f, 0.5f, 0.5f, 1.0f };
float  diffuseLight[4] = { 0.5f, 0.5f, 0.5f, 1.0f };
float specularLight[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

const float *matAmbient = BrassAmbient;
const float *matDiffuse = BrassDiffuse;
const float *matSpecular = BrassSpecular;
float matShininess = BrassShininess;

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpecular);
	glMaterialf(GL_FRONT, GL_SHININESS, matShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();

	glTranslatef(0.0f, -1.0f, -10.0f);
	glRotatef(rotatex, 1.0f, 0.0, 0.0);
	glRotatef(rotatey, 0.0f, 1.0f, 0.0f);

	glutSolidCone(2, 5, 12, 10);

	glPopMatrix();

	glutSwapBuffers();
}

void Idle()
{
	glutPostRedisplay();
}

void Resize(int w, int h)
{
	if (h == 0)
		h = 1;

	glViewport(0, 0, w, h);

	float a = (float)w / (float)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(75.0, a, 0.1, 100);
}

void InitScene()
{
	glClearColor(1, 1, 0, 1);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glFrontFace(GL_CW);
	glShadeModel(GL_FLAT);
}

void MouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		button_state = state;

		if (state == GLUT_DOWN)
		{
			button_x = x;
			button_y = y;
		}
	}
}

void MouseMotion(int x, int y)
{
	if (button_state == GLUT_DOWN)
	{
		rotatey -= (x - button_x) / 2.0;
		button_x = x;
		rotatex -= (y - button_y) / 2.0;
		button_y = y;
		glutPostRedisplay();
	}
}

void Menu(int value)
{
	switch (value)
	{
		// materia≥ - mosiπdz
	case BRASS:
		matAmbient = BrassAmbient;
		matDiffuse = BrassDiffuse;
		matSpecular = BrassSpecular;
		matShininess = BrassShininess;
		break;

		// materia≥ - brπz
	case BRONZE:
		matAmbient = BronzeAmbient;
		matDiffuse = BronzeDiffuse;
		matSpecular = BronzeSpecular;
		matShininess = BronzeShininess;
		break;

		// materia≥ - polerowany brπz
	case POLISHED_BRONZE:
		matAmbient = PolishedBronzeAmbient;
		matDiffuse = PolishedBronzeDiffuse;
		matSpecular = PolishedBronzeSpecular;
		matShininess = PolishedBronzeShininess;
		break;

		// materia≥ - chrom
	case CHROME:
		matAmbient = ChromeAmbient;
		matDiffuse = ChromeDiffuse;
		matSpecular = ChromeSpecular;
		matShininess = ChromeShininess;
		break;

		// materia≥ - miedü
	case COPPER:
		matAmbient = CopperAmbient;
		matDiffuse = CopperDiffuse;
		matSpecular = CopperSpecular;
		matShininess = CopperShininess;
		break;

		// materia≥ - polerowana miedü
	case POLISHED_COPPER:
		matAmbient = PolishedCopperAmbient;
		matDiffuse = PolishedCopperDiffuse;
		matSpecular = PolishedCopperSpecular;
		matShininess = PolishedCopperShininess;
		break;

		// materia≥ - z≥oto
	case GOLD:
		matAmbient = GoldAmbient;
		matDiffuse = GoldDiffuse;
		matSpecular = GoldSpecular;
		matShininess = GoldShininess;
		break;

		// materia≥ - polerowane z≥oto
	case POLISHED_GOLD:
		matAmbient = PolishedGoldAmbient;
		matDiffuse = PolishedGoldDiffuse;
		matSpecular = PolishedGoldSpecular;
		matShininess = PolishedGoldShininess;
		break;

		// materia≥ - grafit (cyna z o≥owiem)
	case PEWTER:
		matAmbient = PewterAmbient;
		matDiffuse = PewterDiffuse;
		matSpecular = PewterSpecular;
		matShininess = PewterShininess;
		break;

		// materia≥ - srebro
	case SILVER:
		matAmbient = SilverAmbient;
		matDiffuse = SilverDiffuse;
		matSpecular = SilverSpecular;
		matShininess = SilverShininess;
		break;

		// materia≥ - polerowane srebro
	case POLISHED_SILVER:
		matAmbient = PolishedSilverAmbient;
		matDiffuse = PolishedSilverDiffuse;
		matSpecular = PolishedSilverSpecular;
		matShininess = PolishedSilverShininess;
		break;

		// materia≥ - szmaragd
	case EMERALD:
		matAmbient = EmeraldAmbient;
		matDiffuse = EmeraldDiffuse;
		matSpecular = EmeraldSpecular;
		matShininess = EmeraldShininess;
		break;

		// materia≥ - jadeit
	case JADE:
		matAmbient = JadeAmbient;
		matDiffuse = JadeDiffuse;
		matSpecular = JadeSpecular;
		matShininess = JadeShininess;
		break;

		// materia≥ - obsydian
	case OBSIDIAN:
		matAmbient = ObsidianAmbient;
		matDiffuse = ObsidianDiffuse;
		matSpecular = ObsidianSpecular;
		matShininess = ObsidianShininess;
		break;

		// materia≥ - per≥a
	case PEARL:
		matAmbient = PearlAmbient;
		matDiffuse = PearlDiffuse;
		matSpecular = PearlSpecular;
		matShininess = PearlShininess;
		break;

		// metaria≥ - rubin
	case RUBY:
		matAmbient = RubyAmbient;
		matDiffuse = RubyDiffuse;
		matSpecular = RubySpecular;
		matShininess = RubyShininess;
		break;

		// materia≥ - turkus
	case TURQUOISE:
		matAmbient = TurquoiseAmbient;
		matDiffuse = TurquoiseDiffuse;
		matSpecular = TurquoiseSpecular;
		matShininess = TurquoiseShininess;
		break;

		// materia≥ - czarny plastik
	case BLACK_PLASTIC:
		matAmbient = BlackPlasticAmbient;
		matDiffuse = BlackPlasticDiffuse;
		matSpecular = BlackPlasticSpecular;
		matShininess = BlackPlasticShininess;
		break;

		// materia≥ - czarna guma
	case BLACK_RUBBER:
		matAmbient = BlackRubberAmbient;
		matDiffuse = BlackRubberDiffuse;
		matSpecular = BlackRubberSpecular;
		matShininess = BlackRubberShininess;
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Program 5");

	InitScene();

	glutDisplayFunc(Display);
	glutIdleFunc(Idle);
	glutReshapeFunc(Resize);
	glutMotionFunc(MouseMotion);
	glutMouseFunc(MouseButton);

	glutCreateMenu(Menu);
	glutAddMenuEntry("Mosiπdz", BRASS);
	glutAddMenuEntry("Brπz", BRONZE);
	glutAddMenuEntry("Polerowany brπz", POLISHED_BRONZE);
	glutAddMenuEntry("Chrom", CHROME);
	glutAddMenuEntry("Miedü", COPPER);
	glutAddMenuEntry("Polerowana miedü", POLISHED_COPPER);
	glutAddMenuEntry("Z≥oto", GOLD);
	glutAddMenuEntry("Polerowane z≥oto", POLISHED_GOLD);
	glutAddMenuEntry("Grafit (cyna z o≥owiem)", PEWTER);
	glutAddMenuEntry("Srebro", SILVER);
	glutAddMenuEntry("Polerowane srebro", POLISHED_SILVER);
	glutAddMenuEntry("Szmaragd", EMERALD);
	glutAddMenuEntry("Jadeit", JADE);
	glutAddMenuEntry("Obsydian", OBSIDIAN);
	glutAddMenuEntry("Per≥a", PEARL);
	glutAddMenuEntry("Rubin", RUBY);
	glutAddMenuEntry("Turkus", TURQUOISE);
	glutAddMenuEntry("Czarny plastik", BLACK_PLASTIC);
	glutAddMenuEntry("Czarna guma", BLACK_RUBBER);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();

	return 0;
}